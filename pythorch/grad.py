import torch
from torch.nn import functional as F


'''
下面主要是对均方误差MSE损失函数的梯度求解示例过程
'''
x = torch.ones(1)
w = torch.full([1], 2)
mse = F.mse_loss(torch.ones(1), x * w) # 求均方误差
print(mse)
# dw = torch.autograd.grad(mse, [w])  不能在这里求解梯度
# 这里w是没有梯度的，必须强制设置梯度属性，并进行更新之后
w.requires_grad_()
# dw = torch.autograd.grad(mse, [w])  没有进行更新，也不能在这里求解梯度
mse = F.mse_loss(torch.ones(1), x * w)
# dw = torch.autograd.grad(mse, [w])  # 第一种方法，返回的是偏微分的list
d = mse.backward()  # 第二种方法，此时返回的是所有需要求解梯度的参数的梯度tensor并保存在该参数的.grad成员变量中
dw_2 = w.grad  # 直接访问w的grad属性即可得到其梯度
# print(dw)
print(dw_2)
# 第一种方法和第二种方法不能同时使用
'''
下面主要是对SoftMax损失函数的梯度求解示例过程
'''
a = torch.rand(3)
a.requires_grad_()
p = F.softmax(a, dim=0)  # 指明维度
# p.backward()  # 报错：grad can be implicitly created only for scalar outputs
ds = torch.autograd.grad(p[1], [a], retain_graph=True)
print(ds)

# 如果需要对其他参数求梯度改变索引即可。

