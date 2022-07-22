#include <stdio.h>
#include "./ex03/ft_div_mod.c"

int main()
{
    printf("===================================================================Test 03 start\n");
    int a, b, div, mod;

    a = 39, b = 9;
    ft_div_mod(a, b, &div, &mod);
    printf("a=%d, b=%d, a / b = %d vs %d, a %% b = %d vs %d\n", a, b, div, a / b, mod, a % b);

    a = 891239, b = 199;
    ft_div_mod(a, b, &div, &mod);
    printf("a=%d, b=%d, a / b = %d vs %d, a %% b = %d vs %d\n", a, b, div, a / b, mod, a % b);

    a = 42, b = -1;
    ft_div_mod(a, b, &div, &mod);
    printf("a=%d, b=%d, a / b = %d vs %d, a %% b = %d vs %d\n", a, b, div, a / b, mod, a % b);

    a = -39918, b = 73100000;
    ft_div_mod(a, b, &div, &mod);
    printf("a=%d, b=%d, a / b = %d vs %d, a %% b = %d vs %d\n", a, b, div, a / b, mod, a % b);

    a = 0, b = 1;
    ft_div_mod(a, b, &div, &mod);
    printf("a=%d, b=%d, a / b = %d vs %d, a %% b = %d vs %d\n", a, b, div, a / b, mod, a % b);

    a = 0, b = -8;
    ft_div_mod(a, b, &div, &mod);
    printf("a=%d, b=%d, a / b = %d vs %d, a %% b = %d vs %d\n", a, b, div, a / b, mod, a % b);

    printf("=====================================================================Test 00 end\n");
    return 0;
}