- [Terminal](#terminal)
  - [Compiling in Terminal](#compiling-in-terminal)
      - [Compiling and Running C Code](#compiling-and-running-c-code)
      - [Compiling C++ Code](#compiling-c-code)

# Terminal
Compiling in Terminal
---
#### Compiling and Running C Code
To compile the hello world example, do the following from within in the `cppenv` bash shell:
```bash
gcc -c hello.c                  # compile hello.c into hello.o
gcc -c main.c                   # compile main.c into main.o
gcc -o hello *.o                # link the two .o files to make an executable
./hello                         # run the new execuable
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