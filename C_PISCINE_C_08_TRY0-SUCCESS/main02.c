#include "./ex02/ft_abs.h"
#include <limits.h>
#include <stdio.h>
int main(){
    printf("ABS(%d):%d\n", 1, ABS(1));
    printf("ABS(%d):%d\n", -1, ABS(-1));
    printf("ABS(%d):%d\n", 1100, ABS(1100));
    printf("ABS(%d):%d\n", -2100, ABS(-2100));
    printf("ABS(%d):%d\n", INT_MAX, ABS(INT_MAX));
    printf("ABS(%d):%d\n", INT_MIN + 1, ABS(INT_MIN + 1));
    return (0);
}