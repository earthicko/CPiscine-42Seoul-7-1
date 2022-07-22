#include <stdio.h>
#include "./ex02/ft_swap.c"

int main()
{
    printf("===================================================================Test 02 start\n");
    int a = 7, b = 15;
    printf("before swap %d %d\n", a, b);
    ft_swap(&a, &b);
    printf("after swap %d %d\n", a, b);
    printf("=====================================================================Test 02 end\n");
    return 0;
}