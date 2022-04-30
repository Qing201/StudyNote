- [Basic Function](#basic-function)
  - [Variables and Types](#variables-and-types)
    - [Datatype](#datatype)
      - [Integer and Float](#integer-and-float)
      - [Boolean](#boolean)
      - [Char and String](#char-and-string)
      - [Nullable](#nullable)
      - [Reference Datatype (Class)](#reference-datatype-class)
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

# Basic Function

## Variables and Types

### Datatype

Data Type | Size | Description
-|-|-
byte | 1 byte | Stores whole numbers from -128 to 127
short | 2 bytes | Stores whole numbers from -32,768 to 32,767
int | 4 bytes | Stores whole numbers from -2,147,483,648 to 2,147,483,647
long | 8 bytes | Stores whole numbers from -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
float | 4 bytes | Stores fractional numbers. Sufficient for storing 6 to 7 decimal digits
double | 8 bytes	| Stores fractional numbers. Sufficient for storing 15 decimal digits
boolean	| 1 bit | Stores true or false values
char | 2 bytes	| Stores a single character/letter or ASCII values

#### Integer and Float
```java
int x = 123;
long longNumber = 1_123_456_789L;       // default is int, need L to set a long
// It is optional to use _(underscore) to separate the number, more readable.

double y = 3.14;
float floatNumber = 10.99F      // default is double, need F to set a float
```

#### Boolean
```java
boolean z = true;  // or false
```
#### Char and String
Char using single 
```java
char symbol = '@';          // single quote
String name = "qing";       // double quote
```

#### Nullable

#### Reference Datatype (Class)
For class datatype, for example class, need use `new` to allocate the memory. Don't need to release the memory, java will automatic release the memory. 
```java
import java.util.Date;          // "java.util" is a package, "Date" is a class

Data now = new Date()
```

Without `new` the reference will point to the same location with same value
```java
Point point1 = new Point(1, 1);
Point point2 = point1       // only copy the reference
point1.x = 2;
system.out.println(point2);         // (2, 1)
```

### Input and Output
#### Print
`System.out.println()`
```java
String x = "world!"

System.out.println("x: " + x);
```


| Escape | Sequence	Description |
| - | -|
| `\t`   | Insert a tab in the text at this point. |
| `\b`   | Insert a backspace in the text at this point. |
| `\n`   | Insert a newline in the text at this point. |
| `\r` 	 | Insert a carriage return in the text at this point. |
| `\f`   | Insert a form feed in the text at this point. |
| `\'`   | Insert a single quote character in the text at this point. |
| `\"`	 | Insert a double quote character in the text at this point. |
| `\\`	 | Insert a backslash character in the text at this point. |
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
