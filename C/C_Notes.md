# C

- [C](#c)
  - [C Fundamentals](#c-fundamentals)
  - [Variables and Types](#variables-and-types)
    - [Datatype](#datatype)
      - [Integer and Float](#integer-and-float)
      - [Boolean](#boolean)
      - [Char and String](#char-and-string)
      - [Nullable](#nullable)
    - [Input and Output](#input-and-output)
      - [Print](#print)
    - [Typecasting](#typecasting)
  - [Collections](#collections)
    - [List](#list)
    - [Set](#set)
    - [Map](#map)
    - [ArrayList](#arraylist)
  - [Control Flows (Logical)](#control-flows-logical)
    - [Logical Operators](#logical-operators)
    - [](#)
      - [if else](#if-else)
      - [switch](#switch)
      - [when](#when)
    - [loop](#loop)
      - [while](#while)
        - [do](#do)
      - [for](#for)
      - [Exiting loop](#exiting-loop)
      - [Safe operation .let](#safe-operation-let)
  - [Pointer](#pointer)
  - [Functions](#functions)
  - [Classes and Objects (inheritance)](#classes-and-objects-inheritance)
    - [Basic Class](#basic-class)
  - [Lambda Expression](#lambda-expression)
  - [Visibility Modifier](#visibility-modifier)
  - [Exception](#exception)
- [Module](#module)
- [Terminal](#terminal)
  - [Compiling in Terminal](#compiling-in-terminal)
      - [Compiling and Running C Code](#compiling-and-running-c-code)
      - [Compiling C++ Code](#compiling-c-code)

## C Fundamentals

#include指令；
#define指令；
类型定义；
外部变量的声明；
除main函数之外的函数的原型；
main函数的定义；
其他函数的定义。
## Variables and Types

### Datatype

```c
char      // 1 bit
short     // 2 bits
int       // 4 bits integer
long      // 4 bits
float     // 4 bits
double    // 8 bits double precision float

sizeof()    // return the size in bits
```

#### Integer and Float

| 类型               | 最小值                     | 最大值                     |
| ------------------ | -------------------------- | -------------------------- |
| short int          | -32 768                    | 32 767                     |
| unsigned short int | 0                          | 65 535                     |
| int                | -2 147 483 648             | 2 147 483 647              |
| unsigned int       | 0                          | 4 294 967 295              |
| long int           | -9 223 372 036 854 775 808 | 9 223 372 036 854 775 807  |
| unsigned long int  | 0                          | 18 446 744 073 709 551 615 |

#### Boolean

#### Char and String

#### Nullable

### Input and Output

```c
int i;
  float x;

  i = 40;
  x = 839.21f;

  printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
  printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);

/*
|40|    40|40   |   040|
|    839.210| 8.392e+02|839.21    |
 */
```

#### Print

### Typecasting

## Collections

### List

### Set

### Map

### ArrayList

## Control Flows (Logical)

### Logical Operators

| Symbol | Meaning          |
| ------ | ---------------- | --- | ---------- |
| !      | logical negation |
| &&     | logical and      |
|        |                  |     | logical or |

###

#### if else

```c
if ( erpression )
  statement
else if ( expression )
  statement
else if ( expression )
  statement
else
  staltement
```

#### switch

```c
switch ( expression ) {
  case constant-expression : statements
  ...
  case constant-expression : statements
  default : statements
}
```

`switch` need `break` to stop the case, or it will continue run the other cases below

```c
// Example without break
switch  (grade)  {
  case 2:   printf("A");
  case 1:   printf("B");
  case 0:   printf("C");
  default:  printf("D");
}

// if grade is 1
// the output will be : BCD
```

#### when

### loop

#### while

##### do

两种语句的区别是，do 语句的循环体至少要执行一次，而 while 语句在控制表达式初始为 0 时会完全跳过循环体。

```c
do {
  statement
} while (expression);
```

#### for

```c
for ( evpr1 ; evpr2 ; evpr3 ) statement

for (i = 10; i > 0; i--)
  printf("T minus %d and counting\n",i);

for (int i = 0,  j = 0; i < n; i++)
```

#### Exiting loop

`break`: 退出循环，进入循环后语句

`continue`: 跳转到下一次 loop 重新开始。

`goto`

#### Safe operation .let


## Pointer

## Functions

## Classes and Objects (inheritance)

### Basic Class

## Lambda Expression

## Visibility Modifier

## Exception

# Module

```c
#include <>
```

# Terminal

## Compiling in Terminal

#### Compiling and Running C Code

To compile the hello world example, do the following from within in the `cppenv` bash shell:

```bash
gcc -c hello.c                  # compile hello.c into hello.o
gcc -c main.c                   # compile main.c into main.o
gcc -o hello *.o                # link the two .o files to make an executable
./hello                         # run the new executable
```

#### Compiling C++ Code

From within in the `cppenv` bash shell,

```bash
cd hello_cpp
g++ -c hello.cc
g++ -c main.cc
g++ -o hello *.o
./hello
```
