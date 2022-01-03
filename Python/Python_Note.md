- [常用术语](#常用术语)
    - [Print()](#print)
- [数组结构](#数组结构)
  - [Set, List, and tuple](#set-list-and-tuple)
    - [list()](#list)
    - [Tuple](#tuple)
    - [Dictionary](#dictionary)
- [GUI (Graph User Interface)](#gui-graph-user-interface)
  - [Game](#game)
- [Data](#data)
  - [File](#file)
    - [Image](#image)
      - [Color](#color)
      - [Edit](#edit)
    - [Excel](#excel)
    - [Word](#word)
  - [正则表达式](#正则表达式)
    - [Python对正则表达式的支持](#python对正则表达式的支持)
- [Multiple Processing](#multiple-processing)
  - [多进程](#多进程)
  - [多线程](#多线程)
  - [多进程+多线程](#多进程多线程)
- [Web](#web)

# 常用术语

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
### Print()
```Python
a, b = 5, 10
print(f'{a} * {b} = {a * b}')
```
`%d`是整数的占位符，`%f`是小数的占位符，`%.2f` stand for float with two decimals, `%%`表示百分号,`%s` is for string.

# [数组结构](Python/Base/07.字符串和常用数据结构.md)

## Set, List, and tuple
```py
A = {} or A = set()     # No dumplicate iterms, Unordered
A = [] or A = list()     
A = () or A = tuple()   # Iterm in tuple can't change
```

###  list()
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
set(A)    # [1,2], not same
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

### Tuple

### Dictionary
[Tutorial](https://realpython.com/python-dicts/)
```py
A = dict()    # Dictionary
items = A.items()   # Return a list of key-values paires in a dictionary
key = A.keys()
values = A.values()
```

# GUI (Graph User Interface)
module [`tkinter`](Python/Python_Module/tkinter)

100-days [GUI Tutorial](Day01-15/10.图形用户界面和游戏开发.md)

## Game
module [`pygame`](Day01-15/10.图形用户界面和游戏开发.md) \
3D Game module: `Panda3D`

# Data

## File
Open files use `open`:
```py
open(file, mode='r', buffering=- 1, encoding=None, errors=None, newline=None, closefd=True, opener=None)
```

| 操作模式 | 具体含义                         |
| -------- | -------------------------------- |
| `'r'`    | 读取 （默认）                    |
| `'w'`    | 写入（会先截断之前的内容）       |
| `'x'`    | 写入，如果文件已经存在会产生异常 |
| `'a'`    | 追加，将内容写入到已有文件的末尾 |
| `'b'`    | 二进制模式                       |
| `'t'`    | 文本模式（默认）                 |
| `'+'`    | 更新（既可以读又可以写）         |

### Image

#### Color

RGB: 
   | 名称  |        RGBA值        |  名称  |       RGBA值       |
   | :---: | :------------------: | :----: | :----------------: |
   | White | (255, 255, 255, 255) |  Red   |  (255, 0, 0, 255)  |
   | Green |   (0, 255, 0, 255)   |  Blue  |  (0, 0, 255, 255)  |
   | Gray  | (128, 128, 128, 255) | Yellow | (255, 255, 0, 255) |
   | Black |    (0, 0, 0, 255)    | Purple | (128, 0, 128, 255) |

#### Edit 
Module: `Pillow`

### Excel
Module: `openpyxl`

### Word
Module: `docx`

## 正则表达式
[《正则表达式30分钟入门教程》](https://deerchao.net/tutorials/regex/regex.htm)，

| 符号               | 解释                                      | 示例             | 说明                                               |
| ------------------ | ----------------------------------------- | ---------------- | -------------------------------------------------- |
| .                  | 匹配任意字符                              | b.t              | 可以匹配bat / but / b#t / b1t等                    |
| \\w                | 匹配字母/数字/下划线                      | b\\wt            | 可以匹配bat / b1t / b_t等<br>但不能匹配b#t         |
| \\s                | 匹配空白字符（包括\r、\n、\t等）          | love\\syou       | 可以匹配love you                                   |
| \\d                | 匹配数字                                  | \\d\\d           | 可以匹配01 / 23 / 99等                             |
| \\b                | 匹配单词的边界                            | \\bThe\\b        |                                                    |
| ^                  | 匹配字符串的开始                          | ^The             | 可以匹配The开头的字符串                            |
| $                  | 匹配字符串的结束                          | .exe$            | 可以匹配.exe结尾的字符串                           |
| \\W                 | 匹配非字母/数字/下划线                    | b\\Wt            | 可以匹配b#t / b@t等<br>但不能匹配but / b1t / b_t等 |
| \\S                 | 匹配非空白字符                            | love\\Syou       | 可以匹配love#you等<br>但不能匹配love you           |
| \\D                 | 匹配非数字                                | \\d\\D           | 可以匹配9a / 3# / 0F等                             |
| \\B                 | 匹配非单词边界                            | \\Bio\\B         |                                                    |
| []                 | 匹配来自字符集的任意单一字符              | [aeiou]          | 可以匹配任一元音字母字符                           |
| [^]                | 匹配不在字符集中的任意单一字符            | [^aeiou]         | 可以匹配任一非元音字母字符                         |
| *                  | 匹配0次或多次                             | \\w*             |                                                    |
| +                  | 匹配1次或多次                             | \\w+             |                                                    |
| ?                  | 匹配0次或1次                              | \\w?             |                                                    |
| {N}                | 匹配N次                                   | \\w{3}            |                                                    |
| {M,}               | 匹配至少M次                               | \\w{3,}           |                                                    |
| {M,N}              | 匹配至少M次至多N次                        | \\w{3,6}          |                                                    |
| \|                 | 分支                                      | foo\|bar         | 可以匹配foo或者bar                                 |
| (?#)               | 注释                                      |                  |                                                    |
| (exp)              | 匹配exp并捕获到自动命名的组中             |                  |                                                    |
| (?&lt;name&gt;exp) | 匹配exp并捕获到名为name的组中             |                  |                                                    |
| (?:exp)            | 匹配exp但是不捕获匹配的文本               |                  |                                                    |
| (?=exp)            | 匹配exp前面的位置                         | \\b\\w+(?=ing)     | 可以匹配I'm dancing中的danc                        |
| (?<=exp)           | 匹配exp后面的位置                         | (?<=\\bdanc)\\w+\\b | 可以匹配I love dancing and reading中的第一个ing    |
| (?!exp)            | 匹配后面不是exp的位置                     |                  |                                                    |
| (?<!exp)           | 匹配前面不是exp的位置                     |                  |                                                    |
| *?                 | 重复任意次，但尽可能少重复 | a.\*b<br>a.\*?b | 将正则表达式应用于aabab，前者会匹配整个字符串aabab，后者会匹配aab和ab两个字符串 |
| +?                 | 重复1次或多次，但尽可能少重复 |                  |                                                    |
| ??                 | 重复0次或1次，但尽可能少重复 |                  |                                                    |
| {M,N}?             | 重复M到N次，但尽可能少重复 |                  |                                                    |
| {M,}?              | 重复M次以上，但尽可能少重复 |                  |                                                    |

### Python对正则表达式的支持

Python提供了`re`模块来支持正则表达式相关操作，下面是re模块中的核心函数。

| 函数                                         | 说明                                                         |
| -------------------------------------------- | ------------------------------------------------------------ |
| compile(pattern, flags=0)                    | 编译正则表达式返回正则表达式对象                             |
| match(pattern, string, flags=0)              | 用正则表达式匹配字符串 成功返回匹配对象 否则返回None         |
| search(pattern, string, flags=0)             | 搜索字符串中第一次出现正则表达式的模式 成功返回匹配对象 否则返回None |
| split(pattern, string, maxsplit=0, flags=0)  | 用正则表达式指定的模式分隔符拆分字符串 返回列表              |
| sub(pattern, repl, string, count=0, flags=0) | 用指定的字符串替换原字符串中与正则表达式匹配的模式 可以用count指定替换的次数 |
| fullmatch(pattern, string, flags=0)          | match函数的完全匹配（从字符串开头到结尾）版本                |
| findall(pattern, string, flags=0)            | 查找字符串所有与正则表达式匹配的模式 返回字符串的列表        |
| finditer(pattern, string, flags=0)           | 查找字符串所有与正则表达式匹配的模式 返回一个迭代器          |
| purge()                                      | 清除隐式编译的正则表达式的缓存                               |
| re.I / re.IGNORECASE                         | 忽略大小写匹配标记                                           |
| re.M / re.MULTILINE                          | 多行匹配标记                                                 |

# Multiple Processing

## 多进程
多任务同时进行，每个进程的内存空间是独立的，变量也是独立的
Using `multiprocessing` Module

## 多线程

```py
from threading import Thread
```

## 多进程+多线程

# Web
