# ****How to Compile C/ C++****

### Compile C program using gcc compiler

* **Step 1. Open up a terminal**

* **Step 2. Use a text editor to create the C source code.**

Enter the C source code below:

```cpp
#include <stdio.h> 

main() {
    printf("Hello World\n");
}
```

* **Step 3. Compile the program.**

Type the command

```bash
``%> `gcc -o hello` `hello.c`
```

 
This command will invoke the GNU C compiler to compile the file `hello.c `and output (-o) the result to an executable called `hello`.
 

* **Step 4. Execute the program.**

Type the command

```bash
`%> ./hello`
```

 
This should result in the output
 
`Hello` `World`
 

* **Optional step**

In order to avoid the.`/` ``prefix each time a program is to be executed, insert the following as the last line in the file `.profile `(located in your home folder):

```bash
`export` ``PATH=.:$PATH``
```


This step needs only to be done once.


### Compile C++ using g++ compiler

* **Step 3. After you have saved the program file, type the command to compile:**

```bash
g++ program.cpp –o program
```

* **Step 4. To run the program, type**

```bash
./program
```
