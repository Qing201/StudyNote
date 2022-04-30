- [Basic Function](#basic-function)
  - [Variables and Types](#variables-and-types)
    - [Datatype](#datatype)
      - [Integer and Float](#integer-and-float)
      - [Boolean](#boolean)
      - [Char and String](#char-and-string)
      - [Nullable](#nullable)
    - [Input and Output](#input-and-output)
      - [Special Built-in Xharacter Literals](#special-built-in-xharacter-literals)
    - [Typecasting](#typecasting)
  - [Collections](#collections)
    - [List](#list)
    - [Set](#set)
    - [Map](#map)
    - [ArrayList](#arraylist)
  - [Writing Expressions](#writing-expressions)
    - [Operators](#operators)
    - [Expression](#expression)
  - [Control Flows (Logical)](#control-flows-logical)
      - [if else](#if-else)
      - [For](#for)
      - [When](#when)
      - [While](#while)
      - [Safe operation .let](#safe-operation-let)
  - [Functions](#functions)
  - [Classes and Objects (inheritance)](#classes-and-objects-inheritance)
    - [Basic Class](#basic-class)
  - [Lambda Expression](#lambda-expression)
  - [Visibility Modifier](#visibility-modifier)
  - [Exception](#exception)


# Basic Function

## Variables and Types

### Datatype

```cpp
char      // 1 bit
short     // 2 bits
int       // 4 bits integer
long      // 4 bits
float     // 4 bits 
double    // 8 bits double precision float

const int a = 1;  // constant value (cannot change)

sizeof()    // reture the size in bits
```

#### Integer and Float

#### Boolean

#### Char and String

#### Nullable

### Input and Output

The Standard C++ input/output library is `iostream`
```cpp
#include <iostream>
cin >> <>;
cout << <>;
```
Input operator: `>>`
Output operator: `<<`

#### Special Built-in Xharacter Literals
```cpp
'\n'    // newline
'\t'    // tab
'\0'    // null
'\''    // single quote
'\"'    // double quote
'\\'    // backslash
```

### Typecasting

## Collections

### List 

### Set

### Map

### ArrayList


## Writing Expressions

### Operators
```cpp
a = 0;
cout << a++;    // output a before added, 0

a = 0;
cout << ++a;    // output a after added, 1
```

### Expression
```cpp
cout << (a == b ? ' ' : '\n');      // output ' ' if a == b and output '\n' if a != b)
```

## Control Flows (Logical)



#### if else
#### For
#### When
#### While
#### Safe operation .let
## Functions
## Classes and Objects (inheritance)
### Basic Class

## Lambda Expression
## Visibility Modifier
## Exception
