# GNU Compiler Collection (GCC)

- [GNU Compiler Collection (GCC)](#gnu-compiler-collection-gcc)
  - [GCC](#gcc)
  - [Makefile](#makefile)
  - [XMake](#xmake)

## GCC

GCC 编译工具链（toolchain），是指以 GCC 编译器为核心的一整套工具。它主要包含以下三部分内容：

**gcc-core**：即 GCC 编译器，用于完成预处理和编译过程，把 C 代码转换成汇编代码。
**Binutils**：除 GCC 编译器外的一系列小工具包括了链接器 ld，汇编器 as、目标文件格式查看器 readelf 等。
**glibc**：包含了主要的 \C 语言标准函数库，C 语言中常常使用的打印函数 printf、malloc 函数就在 glibc 库中。

GCC 编译工具链在编译一个 C 源文件时需要经过以下 4 步：

预处理：为把头文件的代码、宏之类的内容转换成生成的.i 文件，还是 C 代码。
编译：把预处理后的.i 文件通过编译成.s 文件，汇编语言。
汇编：将汇编语言文件生成目标文件.o 文件，机器码。
链接：将每个源文件对应的.o 文件链接起来，就生成一个可执行程序文件。


**动态链接和静态链接：**
动态链接：GCC编译时的默认选项。动态是指在应用程序运行时才去加载外部的代码库，不同的程序可以共用代码库。 所以动态链接生成的程序比较小，占用较少的内存。
静态链接：链接时使用选项 “--static”，它在编译阶段就会把所有用到的库打包到自己的可执行程序中。 所以静态链接的优点是具有较好的兼容性，不依赖外部环境，但是生成的程序比较大。


```sh
gcc hello.c -o hello
```

## Makefile



## XMake
