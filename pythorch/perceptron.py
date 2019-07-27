
'''
单层感知器的梯度求解
'''

import torch
from torch.nn import functional as F

x = torch.randn(1, 10)
w = torch.randn(1, 10, requires_grad=True)  # 强制设置梯度
o = torch.sigmoid(x @ w.t())  # 得到经过一个激活函数的输出output
loss = F.mse_loss(torch.ones(1, 1), o)  # 计算损失函数，理想输出与函数输出的结果的均方误差
loss.backward()  # 计算损失函数的梯度
print(w.grad)  # 访问w的梯度

'''
多层感知器的梯度求解
'''
x_m = torch.randn(1, 10)
w_m = torch.randn(2, 10, requires_grad=True)

o_m = torch.sigmoid(x_m @ w_m.t())
loss_m = F.mse_loss(torch.ones(1, 2), o_m)
loss_m.backward()  # 求解所有需要求解梯度的参数的梯度
print(w_m.grad)  # 返回的是一个2维的tensor

'''
链式法则的实现
'''
# 输入参数，两层感知器
x = torch.tensor(1.)
w1 = torch.tensor(2., requires_grad=True)
b1 = torch.tensor(1., requires_grad=True)
w2 = torch.tensor(2., requires_grad=True)
b2 = torch.tensor(1., requires_grad=True)

# 输入节点，第一个节点y1，表示x经过w1和b1的线性变换输出为y1，
# 第二个节点表示第一个节点的输出经过w2和b2的线性变换后得到的输出结果y2
y1 = x * w1.t() + b1
y2 = y1 * w2.t() + b2

# y2对各部分参数的梯度，注意这里要保持梯度性质
dy2_dy1 = torch.autograd.grad(y2, [y1], retain_graph=True)[0]
dy2_dw2 = torch.autograd.grad(y2, [w2], retain_graph=True)[0]
dy2_db2 = torch.autograd.grad(y2, [b2], retain_graph=True)[0]
dy2_dw1 = torch.autograd.grad(y2, [w1], retain_graph=True)[0]
dy2_db1 = torch.autograd.grad(y2, [b1], retain_graph=True)[0]
# y1对各部分的参数梯度，同样需要保持求解梯度的性质
dy1_dw1 = torch.autograd.grad(y1, [w1], retain_graph=True)[0]
dy1_db1 = torch.autograd.grad(y1, [b1], retain_graph=True)[0]
# 利用链式法则对第一部分的参数求梯度
dy2_dw1_line = dy2_dy1 * dy1_dw1
dy2_db1_line = dy2_dy1 * dy1_db1
# 比较直接由pytorch求解梯度和用链式法则求解梯度的
print('直接求解y2对w1的梯度：', dy2_dw1,  '利用链式法则得到的y2对w1的梯度：', dy2_dw1_line)
print('直接求解y2对b1的梯度：', dy2_db1,  '利用链式法则得到的y2对b1的梯度：', dy2_db1_line)



