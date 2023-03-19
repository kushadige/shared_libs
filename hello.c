#include <stdio.h>

int my_add(int a, int b);
int my_subtract(int a, int b);

int main(int argc, char **argv) {
    printf("1+1=%d\n", my_add(1,1));
    printf("1+1=%d\n", my_add(2,3));
    printf("1+1=%d\n", my_add(8,6));
    printf("1-1=%d\n", my_subtract(1,1));
    printf("1+1=%d\n", my_subtract(2,3));
    printf("1+1=%d\n", my_subtract(8,6));
    return 0;
}