gcc -o my_math.dll -fpic -shared my_math.c
gcc hello.c -L. -lmy_math -o hello