#include <stdio.h>
#include "./ex00/ft_ft.c"

int main()
{
    printf("===================================================================Test 00 start\n");
    int buffer = 0;
    printf("Before ft_ft: %d\n", buffer);
    ft_ft(&buffer);
    printf("After ft_ft: %d\n", buffer);
    printf("should be: 42\n");
    printf("=====================================================================Test 00 end\n");
    return 0;
}