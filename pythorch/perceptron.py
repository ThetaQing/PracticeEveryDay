
'''
单层感知器和多层感知器的梯度求解
'''

import torch
from torch.nn import functional as F

x = torch.randn(1, 10)
w = torch.randn(1, 10, requires_grad=True)
o = torch.sigmoid(x @ w.t())
loss = F.mse_loss(torch.ones(1, 1), o)
loss.backward()
print(w.grad)