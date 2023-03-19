# Shared Libs with C (windows ".dll", linux ".so" files)

```c
#include <stdio.h>

int main(int argc, char **argv) {
    printf("Hello, World!\n");
    printf("Another Hello, World!\n");
    printf("Another one again..\n");
    return 0;
}
```

`gcc -c test.c` -> To generate an object file (`.o' file):


## COMPILATION PROCESS

`source.c`  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;v  
`source.i`  

    preprocessor step ( #include, #define, #if... ) 
    gcc -E source.c > source.i  || gcc -E -P source.c > source.i

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;v  
`source.s`  

    compiler step ( MOV $1, register..)
    gcc -S source.c
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;v  
`source.o`  

    assembler step ( generates valid machine code for your architecture, 010100101 )
    gcc -c source.c
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;v  
`linker`  

    this is where we bring in other libraries. maybe other ".o" files (printf.o) 
    - Static Linker 
    - Dynamic Linker

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;v  
`source.exe`

    gcc source.c -o source


## errors in linking process

When we try to compile hello.c file with "gcc hello.c -o hello" command, without linking the functions "my_add" and "my_subtract", it says:
    
    * undefined reference to `my_add'
    * undefined reference to `my_subtract'

We cannot compile it without linking.. but we can actually look up the compilation output with using "gcc -c hello.c" command. (this because it is "assembler" step that is the top of "linker")


## build commands
gcc -o my_math.dll -fpic -shared my_math.c

-fpic -> it used for extending the library accessibility to entire computer

nm my_math.dll (to check your library)

## linking libraries
gcc hello.c -L. -lmy_math -o hello

## compilation out
6486 0700 0000 0000  
ae03 0000 1800 0000  
0000 0400 2e74 6578  
7400 0000 0000 0000  
0000 0000 4001 0000  
2c01 0000 dc02 0000  
0000 0000 0f00...


https://www.ibm.com/docs/en/zos/2.1.0?topic=dlls-building-dll  
https://en.wikipedia.org/wiki/Dynamic-link_library
