#include <stdio.h>
#include "./ex04/ft_ultimate_div_mod.c"

int main()
{
    printf("===================================================================Test 04 start\n");
    int a, b, div, mod;

    a = 39, b = 9;
    div = a / b, mod = a % b;
    printf("a=%d, b=%d, ", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("a / b = %d vs %d, a %% b = %d vs %d\n", a, div, b, mod);

    a = 891239, b = 199;
    div = a / b, mod = a % b;
    printf("a=%d, b=%d, ", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("a / b = %d vs %d, a %% b = %d vs %d\n", a, div, b, mod);

    a = 43, b = -7;
    div = a / b, mod = a % b;
    printf("a=%d, b=%d, ", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("a / b = %d vs %d, a %% b = %d vs %d\n", a, div, b, mod);

    a = -5, b = 3;
    div = a / b, mod = a % b;
    printf("a=%d, b=%d, ", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("a / b = %d vs %d, a %% b = %d vs %d\n", a, div, b, mod);

    a = -39918, b = 73100000;
    div = a / b, mod = a % b;
    printf("a=%d, b=%d, ", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("a / b = %d vs %d, a %% b = %d vs %d\n", a, div, b, mod);

    a = 39918, b = -73100000;
    div = a / b, mod = a % b;
    printf("a=%d, b=%d, ", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("a / b = %d vs %d, a %% b = %d vs %d\n", a, div, b, mod);

    a = 0, b = 1;
    div = a / b, mod = a % b;
    printf("a=%d, b=%d, ", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("a / b = %d vs %d, a %% b = %d vs %d\n", a, div, b, mod);

    a = 0, b = -8;
    div = a / b, mod = a % b;
    printf("a=%d, b=%d, ", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("a / b = %d vs %d, a %% b = %d vs %d\n", a, div, b, mod);

    printf("=====================================================================Test 04 end\n");
    return 0;
}