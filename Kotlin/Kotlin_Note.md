- [Basic Function](#basic-function)
  - [Variables and Types](#variables-and-types)
    - [Datatype](#datatype)
      - [Integer and Float](#integer-and-float)
      - [Boolean](#boolean)
      - [Char and String](#char-and-string)
      - [Nullable](#nullable)
    - [Input and Output](#input-and-output)
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
  - [Functions](#functions)
  - [Classes and Objects (inheritance)](#classes-and-objects-inheritance)
    - [Basic Class](#basic-class)
      - [Member Variables (Properties)](#member-variables-properties)
      - [Member Secondary Constructor](#member-secondary-constructor)
      - [Custom Getter and Setter](#custom-getter-and-setter)
        - [Private set](#private-set)
    - [Data Class](#data-class)
    - [Parent and Child Class](#parent-and-child-class)
      - [Parent Class](#parent-class)
      - [Child Class](#child-class)
    - [Interface](#interface)
    - [abstract class](#abstract-class)
  - [Lambda Expression](#lambda-expression)
  - [Operator](#operator)
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

### Typecasting
```kt
val obj: Any = 123
val str: String? = obj as? String      // str will set if obj is a string, null if not string
print(str)      // print null
```


## Collections
### List 
List can and different type of data.
```kt
val myList = ListOf("A", 1, Class())      // this list cannot modify

mutableMyList = myList.toMutableList()
val mutableMyList = mutableListOf()      // can modify

println(myList[0])
println(myList.contentToString)

mutableMyList.add('A')
mutableMyList.addAll(myList)         // add another list
mutableMyList.removeAt(index)        // remove the element with index 


for(index in myList.indices){...}

```

### Set
Set will not have the duplicate elements.
```kt
val mySet = setOf("A", "A", "B")
print(mySet.size)                   // print 2, because two "A" will become one "A"

mySet.toSortedMap()
```

### Map
```kt
val week = mapOf(1 to "Mon", 2 to "Tue", 3 to "Wed")
print(week[2])          // "Tue" with key not index

```

### ArrayList
```kt
val myArrayList : ArrayList<String>()
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
```kt
fun myFunction(){
    // ...
}
```
## Classes and Objects (inheritance)

### Basic Class
```kt
class Person(firstName: String = "Qingchuan", lastName: String = "Hou"){
    
    // Member Variables - Properties

    // initializer block, run when create
    init {
        // ...
    }

    // Member Secondary Constructor
}
```

#### Member Variables (Properties)

```kt
    var age : Int? = null
    var hobby : String = "Basketball"
    lateinit var height: String
```

To change the member variables
```kt
fun main(){
    var qing = Person()
    qing.age = 24
}
```

#### Member Secondary Constructor
```kt
    // 'this' here to get the initialize properties
    constructor(firstName: String, lastName: String, age: Int): this(firstName, lastName){
        this.age = age          // 'this' here is the member variable
    }
```
To using this constructor
```kt
fun main(){
    var qing = Person(age: 24)
}
```

#### Custom Getter and Setter
Getter and setter is used in initial variables
Getter: set what to output when get the variable outside of class
Setter: how to change the variable when set it outside of class

```kt
    var weight: Int = 65
        get() {
            return field * 2
        }
        set(value){
            field = if(value > 0) value else throw IllegalArgumentException("Weight cannot < 0")
        }
```

##### Private set
```kt
    // this variable can be only set inside the class, but can still get outside
    var gender : String = "Male"
        private set
```

### Data Class
```kt
data class User(val id: Long, val name: String)

fun main(){
    val user1 = User(id:1, name:"A")

    val user2 = user1.copy(name = "Qing")           // Only name will change
    
    println(user2.component1())     // 1
    println(user2.component2())     // "qing"
    
    val (id,name) = user2           // id = 1, name = "qing"
}
```

### Parent and Child Class

#### Parent Class
Super class or Base class or Parent class
```kt
// using 'open' to allow other child class to access
open class Car(val name: String, val brand: String){
    
    open var range = 200.0          // 'open' to allow child class override

    open fun 
}
```

#### Child Class
Child class or Sub class
```kt
class ElectricCar(name: String, brand: String, batteryLife: Double)
    : Car (name, brand){
    
    override var range = batteryLife * 5        // 'override' the var in parent class
}
```

### Interface
Interface is using to made class's components, (kind of sub class of class)
```kt
interface Drivable{
    val maxSpeed: Double
    fun drive(): String
    fun brake(){
        println("car is braking")
    }
}
```

Class using interface
```kt
// add maxSpeed
open class Car(val name: String, val brand: String, val maxSpeed: Double): Drivable{
    
    // we must set the var and fun which not default in interface
    // brake() is default in interface, so it is not must need to set.

    override fun drive(): String = "drive from interface"
    // or (same)
    override fun drive(): String {
        return "drive from interface"
    }
}
```

for the child of a using interface class
```kt
class electricCar(...){
    override fun brake() {
        super.brake()           // using 'super' to call the function in interface
        println("This is a electricCar")
    }
}
```

Interface is also can be inter the Interface

### abstract class
abstract is for the parent class, and the abstract var and fun must be override in child class
```kt
abstract class (...) {

    var ...
    abstract var ...

    fun
    abstract fun ...
}
```
abstract class can have the normal var and fun which don't need to override in child class


## Lambda Expression















## Operator

# Android Studio

```kt
Toast.makeTest(){}
```