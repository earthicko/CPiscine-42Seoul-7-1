#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_CASE 6

char *ft_strdup(char *src);

int main()
{
    char *str[10] =
        {
            "Hello, World!",
            "strstr",
            "null in middle\0after null",
            "\0",
            "\0afternull",
            ""};

    printf("Test 00 ft_strdup======================================\n");

    for (int i = 0; i < N_CASE; i++)
    {
        char *dest[2];

        dest[0] = strdup(str[i]);
        dest[1] = ft_strdup(str[i]);

        if (strcmp(dest[0], dest[1]) != 0)
        {
            printf("\tFailure while strdup :%s:\n", str[i]);
            printf("\tstd::strdup:%s:\n", dest[0]);
            printf("\tusr::strdup:%s:\n", dest[1]);
        }
        else
        {
            printf("Success\n");
        }
        free(dest[0]);
        free(dest[1]);
    }

    printf("Test 00 ft_strdup======================================\n");

    return 0;
}