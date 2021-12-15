- [Python](#python)
  - [常用术语](#常用术语)
  - [Set, List, and tuple](#set-list-and-tuple)
    - [list](#list)
  - [Dictionary - dic()](#dictionary---dic)

# Python 

## 常用术语

```py
a = 100
b = 12.345
c = 1 + 5j
d = 'hello, world'
e = True
print(type(a))    # <class 'int'>
print(type(b))    # <class 'float'>
print(type(c))    # <class 'complex'>
print(type(d))    # <class 'str'>
print(type(e))    # <class 'bool'>
```

- `int()`：将一个数值或字符串转换成整数，可以指定进制。
- `float()`：将一个字符串转换成浮点数。
- `str()`：将指定的对象转换成字符串形式，可以指定编码。
- `chr()`：将整数转换成该编码对应的字符串（一个字符）。
- `ord()`：将字符串（一个字符）转换成对应的编码（整数）。

```py
a = int(input('a = '))
b = int(input('b = '))
print('%d + %d = %d' % (a, b, a + b))
```

`%d`是整数的占位符，`%f`是小数的占位符，`%.2f` stand for float with two decimals, `%%`表示百分号,`%s` is for string.


## Set, List, and tuple
```py
A = {} or A = set()     # No dumplicate iterms, Unordered
A = [] or A = list()     
A = () or A = tuple()
```

###  list
```py
A = [(1,2),(3,4)]
print(A[0],type(A[0]))        # (1,2), tuple
print(A[0][1],type(A[0][1]))  # 2, int
```
Operation:
```py
A = [(1,2)]
B = [(3,4)]
print(A + B)    # [(1,2),(3,4)]
set(A)    # [1,2], not same with A

## Numpy
x = np. arange(1,10)   #从1到10的array

x = np.reshape(n,m)     # 变成n*m的matrix
```

```py
A = ['12']    # type(A[0]) = str
B = set()
B += A[0]     # B = ['1','2']
C += [A[0]]   # C = ['12']
```

```py
list.count(a)    # The number of a in list (Dumplicate)
list.sort()      # Sort list
```

## Dictionary - dic()
[Link](https://realpython.com/python-dicts/)