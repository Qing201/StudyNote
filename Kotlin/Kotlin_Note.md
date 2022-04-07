- [Basic Function](#basic-function)
  - [Variables and Types](#variables-and-types)
    - [Datatype](#datatype)
      - [Integer and Float](#integer-and-float)
      - [Boolean](#boolean)
      - [Char and String](#char-and-string)
      - [Nullable](#nullable)
    - [Input and Output](#input-and-output)
  - [Control Flows (Logical)](#control-flows-logical)
      - [if else](#if-else)
      - [For](#for)
      - [When](#when)
      - [While](#while)
  - [Functions](#functions)
  - [collections](#collections)
  - [Classes and Objects (inheritance)](#classes-and-objects-inheritance)
  - [Operator](#operator)
  - [List](#list)
  - [Class](#class)
- [Android Studio](#android-studio)


# Basic Function

## Variables and Types

Different between `var` and `val`:
- `var` is changeable
- `val` is not changeable
```kt
var x: Int = __
//or
var x = __

val x: Int = __         // not changeable
```

### Datatype

#### Integer and Float
Integer types: default is `Int`
`Byte` (8 bit), `Short` (16 bit), `Int` (32 bit), `Long` (64 bit)

Floating Point number types: default is `Double`
`Float` (32 bit), `Double` (64 bit)

```kt
var x = 1           // Int
var x = 1L          // Long
var x = 1.1         // Double
var x = 1.1f        // Float
```

#### Boolean
```kt
var bool = true
//or 
var bool: Boolean = true
```

#### Char and String
```kt
var letter = 'a'                // char
var string = "Hello World!"     // string

string[0]                       // first character 'H'
string[string.length - 1]       // last character '!'

string.toUpperCase()
```

#### Nullable
The variable in kotlin cannot be set to the null type by default. To set a variable can be null using `?`

```kt
var nullableName : String? = "Hello"
nullableName = null
```

Also using `?` with a null variable, otherwise will cause a error.
```kt
var len2 = nullableName?.length

// the logic of this function with ? is same with logic below

if (nullableName |= null) {
    var len2 = nullableName.length
}else{
    null
}
```

Using `!!` if you sure that a nullable variable is not null
```kt
println(nullableName!!.toLowerCase())
```

**Safe Chain**
```
val wifesAge: String? = user?.wife?.age? : 0
```

### Input and Output
```kt
val myStr = "World"

print(" Hello $myStr")
print("Number of char is ${myStr.length})

val x = readLine()

val number = readLine() ?: "0"          // Sign 0 if it is none

```

## Control Flows (Logical)

#### if else
```kt
if (1st condition) {
    // first if 
} else if(2nd condition){
    // 2nd
) else {
    // other
}

val y = if (condition) 0 else 1
```

#### For
```kt
for (i in 1..100) {
    println(i)
}

for (i in 1 until 10){
    // ...
}

for (i in 10 downTo 1 step 2){
    // ...
}
```

#### When
When loop for different cases
```kt
when(x) {
    in 1..50 -> println()
    in 51..100 -> println()
    1, 2, 3 -> println()
    else -> {
        println()
    }
}
```

```kt
var X : Any = 13.37f
when (x){
    is Int -> println("$x is an Int")
    !is Double -> println("$x is not a Double")
    is String -> println("§x is a String")
    else -> println("$x is none of the above")
}
```

#### While

**do while**
This will do at least once in `do{}`
```kt
var x = 10
do{
    print("$x")         // will print 10
    x++
} while (x < 10)
print("$x")             // x = 11

```


## Functions
## collections
## Classes and Objects (inheritance)

## Operator

## List 
```kt
val list = ListOf("A", "B", "C")
println(list[0])

val list = mutableListOf()      // can modify
list.add('A')
```


## Class

```kt
class
```

# Android Studio

```kt
Toast.makeTest(){}
```