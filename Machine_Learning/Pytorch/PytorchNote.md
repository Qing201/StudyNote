```py
torch.eig()
```

### Gradient
```py
x = torch.arange(4.0)
x.requires_grad_(True)  # Same as `x = torch.arange(4.0, requires_grad=True)`
x.grad  # The default value is None\

y = 2 * torch.dot(x, x)

y.backward()
x.grad
x.grad == 4 * x     # true
```

```py
x.grad.zero_()
y = x * x
u = y.detach()      # Treat u as a constant when do the backward() 
z = u * x

z.sum().backward()
x.grad == u
```