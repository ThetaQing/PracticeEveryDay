import torch
from torch.nn import functional as f
# Sigmoid函数
x_sig = torch.linspace(-100, 100, 10)
y_sig_1 = torch.sigmoid(x_sig)
y_sig_2 = f.sigmoid(x_sig)  # 将被移除，建议使用torch.sigmoid

# ReLU函数
x_R = torch.linspace(-1, 1, 10)
y_R_1 = torch.relu(x_R)
y_R_2 = f.relu(x_R)

print(y_R_1)



