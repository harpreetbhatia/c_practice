# How to Compile C/ C++

#### Compile **C** program using gcc compiler

* **Step 1.** Compile the program.
```bash
gcc -o hello hello.c
```

 
This command will invoke the GNU C compiler to compile the file hello.c and output (-o) the result to an executable called hello.
 

* **Step 2.** Execute the program.
```bash
./hello
```

 
This should result in the output
 ```bash
Hello World
 ```

* **Step 3.** (Optional)

In order to avoid the `./` prefix each time a program is to be executed, insert the following as the last line in the file `.profile `(located in your home folder):
```bash
export `PATH=.:$PATH`
```
This step needs only to be done only once.




#### Compile **C++** program using g++ compiler

* **Step 1.** After you have saved the program file, type the command to compile:
```bash
g++ program.cc –o program
```

* **Step 2.** To run the program, type:
```bash
./program
```

