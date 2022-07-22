#include <stdio.h>
#include "./ex05/ft_putstr.c"

int main()
{
    printf("===================================================================Test 05 start\n");
    fflush(stdout);

    char *strs[6];
    strs[0] = "Hello, World!\n";
    strs[1] = "\0empty";
    strs[2] = "099\t\t 94\n\nsadk";
    strs[3] = "null";
    strs[4] = "null in middle\0null after";
    strs[5] = "";

    for (int i = 0; i < 6; i++)
    {
        printf("str%d start:", i);
        fflush(stdout);
        ft_putstr(strs[i]);
        printf(":%s:str%d end\n", strs[i], i);
        fflush(stdout);
    }
    printf("=====================================================================Test 05 end\n");
    return 0;
}