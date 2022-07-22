#include <stdio.h>
#include "./ex08/ft_sort_int_tab.c"

int print_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    printf("===================================================================Test 08 start\n");

    int tab0[3] = {2, 3, 1};
    int tab1[6] = {2, 3, 1, -2147483648, 0, 2147483647};
    int tab2[1] = {42};
    int tab3[10] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
    int tab4[7] = {-2147483648, 2147483647, -2147483648, 2147483647, -2147483648, 2147483647, 0};

    printf("before sort:\n");
    print_arr(tab0, 3);
    printf("after sort:\n");
    ft_sort_int_tab(tab0, 3);
    print_arr(tab0, 3);

    printf("before sort:\n");
    print_arr(tab1, 6);
    printf("after sort:\n");
    ft_sort_int_tab(tab1, 6);
    print_arr(tab1, 6);

    printf("before sort:\n");
    print_arr(tab2, 1);
    printf("after sort:\n");
    ft_sort_int_tab(tab2, 1);
    print_arr(tab2, 1);

    printf("before sort:\n");
    print_arr(tab3, 10);
    printf("after sort:\n");
    ft_sort_int_tab(tab3, 10);
    print_arr(tab3, 10);

    printf("before sort:\n");
    print_arr(tab4, 7);
    printf("after sort:\n");
    ft_sort_int_tab(tab4, 7);
    print_arr(tab4, 7);

    printf("=====================================================================Test 08 end\n");
    return 0;
}