- [Basic Function](#basic-function)
  - [Variables and Types](#variables-and-types)
    - [Datatype](#datatype)
      - [Integer and Float](#integer-and-float)
      - [Boolean](#boolean)
      - [Char and String](#char-and-string)
      - [Nullable](#nullable)
      - [Reference Datatype (Class)](#reference-datatype-class)
    - [Constants](#constants)
    - [Input and Output](#input-and-output)
      - [Input](#input)
      - [Print](#print)
    - [Typecasting](#typecasting)
      - [Operation](#operation)
      - [String Casting](#string-casting)
      - [Number Casting](#number-casting)
  - [Operation](#operation-1)
    - [Arithmetic Expression](#arithmetic-expression)
    - [Logic Operator](#logic-operator)
  - [Collections](#collections)
    - [Arrays](#arrays)
      - [Multiple Dimensions Array](#multiple-dimensions-array)
    - [List](#list)
    - [Set](#set)
    - [Map](#map)
    - [ArrayList](#arraylist)
  - [Control Flows](#control-flows)
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
  - [NumberFormat()](#numberformat)

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

String inputName = "  Qing";
String name = inputName.trim()      // "Qing", removed the front space
```

String is a class. In java String is unchangeable, the operation for string will always create a new string. Ex:`string.toLowerCase()` will not change the original `string`

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

| Escape | Sequence	Description |
| - | :-: |
| `\t`   | tab |
| `\b`   | backspace|
| `\n`   | newline|
| `\r` 	 | carriage return |
| `\f`   | form feed |
| `\'`   | single quote character |
| `\"`	 | double quote character |
| `\\`	 | backslash character |

### Constants
```java
final float pi = 3.14       // cannot change later
```

### Input and Output

#### Input
```java
Scanner scanner = new Scanner(System.in)
byte age = scanner.nextByte();

// if input string, Ex: "Qing Hou"
String age = scanner.next();        // Qing
String name = scanner.nextLine();   // Qing Hou
```

#### Print
`System.out.println()`
```java
String x = "world!"

System.out.println("x: " + x);
```

### Typecasting

#### Operation
The shorter memory data can be casted to a long memory data
byte > short > int > long > float > double
```java
int y = 1;
double x = y + 1;   // b/c double is longer than int
```

#### String Casting
```java
String x = "1";
int y = Integer.parseInt(x)
```

#### Number Casting
```java
int result = (int)Math.round(1.1F);
int result = (int)Math.ceil(1.1F);        // 2
int result = (int)Math.floor(1.1F);       // 1
int result = (int)Math.max(1, 2);
double result = Math.random();
```

## Operation
### Arithmetic Expression
```java
int result = 10 / 3                        // 3
double result = (double)10 / (double)3;       // 3.3333..
```

```java 
int x = 1;
int y = ++x;        // y = 2, x = 2
int z = x++;        // z = 2, x = 3
```
### Logic Operator

- `&&`: and
- `||`: or



## Collections

### Arrays
Arrays in java have the fixed length
```java
int[] numbers = new int[5]      // 5 length int array
int[] numbers2 = {2, 3, 4, 5, 6}
```
Array in java is save the location in memory, to print the values in array use `Arrays.toString()`

```java
System.out.println(Arrays.toString(numbers))
```

#### Multiple Dimensions Array
```java
int[][] numbers2d = new int[5][2]
int[][] numbers2d = {{1, 2, 3}, {4, 5, 6}}

int[][][] numbers3d = new int[5][2][2]

System.out.println(Arrays.deepToString(numbers))     // deepToString()
```

### List 

### Set

### Map

### ArrayList

## Control Flows

#### if else
```java
if () {
    // ...
} else if {
    // ...
} else {
    // ...
}
```


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

## NumberFormat()
```java
String result = NumberFormat.getPercentInstance().format(1234.56);       // "$1,234.56"

String result = NumberFormat.getPercentInstance().format(.56);      // "56%"
```