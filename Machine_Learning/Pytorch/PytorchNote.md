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

### `enumerate()`

```py
# Python program to illustrate
# enumerate function in loops
l1 = ["eat", "sleep", "repeat"]
  
# printing the tuples in object directly
for ele in enumerate(l1):
    print (ele)
  
# changing index and printing separately
for count, ele in enumerate(l1, 100):
    print (count, ele)
  
# getting desired output from tuple
for count, ele in enumerate(l1):
    print(count)
    print(ele)
```

```
(0, 'eat')
(1, 'sleep')
(2, 'repeat')
100 eat
101 sleep
102 repeat
0
eat
1
sleep
2
repeat
```