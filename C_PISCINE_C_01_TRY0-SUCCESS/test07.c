#include <stdio.h>
#include "./ex07/ft_rev_int_tab.c"

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
    printf("===================================================================Test 07 start\n");
    int tab0[5] = {1, 2, 3, 4, 5};
    int tab1[4] = {1, 2, 3, 4};
    int tab2[6] = {1, 2, 3, 4, 5, 6};
    int tab3[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    printf("before rev:\n");
    print_arr(tab0, 5);
    ft_rev_int_tab(tab0, 5);
    printf("after rev:\n");
    print_arr(tab0, 5);

    printf("before rev:\n");
    print_arr(tab1, 4);
    ft_rev_int_tab(tab1, 4);
    printf("after rev:\n");
    print_arr(tab1, 4);

    printf("before rev:\n");
    print_arr(tab2, 6);
    ft_rev_int_tab(tab2, 6);
    printf("after rev:\n");
    print_arr(tab2, 6);

    printf("before rev:\n");
    print_arr(tab3, 11);
    ft_rev_int_tab(tab3, 11);
    printf("after rev:\n");
    print_arr(tab3, 11);

    printf("before rev:\n");
    print_arr(tab0, 5);
    ft_rev_int_tab(tab0, 0);
    printf("after rev (size 0):\n");
    print_arr(tab0, 5);

    printf("before rev:\n");
    print_arr(tab0, 5);
    ft_rev_int_tab(tab0, 1);
    printf("after rev (size 1):\n");
    print_arr(tab0, 5);

    printf("before rev:\n");
    print_arr(tab0, 5);
    ft_rev_int_tab(tab0, 2);
    printf("after rev (size 2):\n");
    print_arr(tab0, 5);

    printf("=====================================================================Test 07 end\n");
    return 0;
}