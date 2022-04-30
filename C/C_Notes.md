- [Basic Function](#basic-function)
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
- [Module](#module)
- [Terminal](#terminal)
  - [Compiling in Terminal](#compiling-in-terminal)
      - [Compiling and Running C Code](#compiling-and-running-c-code)
      - [Compiling C++ Code](#compiling-c-code)

# Basic Function

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

#### Boolean

#### Char and String

#### Nullable

### Input and Output
#### Print

### Typecasting

## Collections

### List 

### Set

### Map

### ArrayList

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

# Module
```c
#include <>
```

# Terminal
Compiling in Terminal
---
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

