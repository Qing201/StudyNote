# Basic C++

## Data Type

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

## Input and Output
The Standard C++ input/output library is `iostream`
```cpp
#include <iostream>
cin >> <>;
cout << <>;
```
Input operator: `>>`
Output operator: `<<`

### Special Built-in Xharacter Literals
```cpp
'\n'    // newline
'\t'    // tab
'\0'    // null
'\''    // single quote
'\"'    // double quote
'\\'    // backslash
```

## Writing Expressions

### Opratores
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

