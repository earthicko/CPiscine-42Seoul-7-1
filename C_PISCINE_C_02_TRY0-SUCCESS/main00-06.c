#include <stdio.h>
#include <string.h>

#define L_MAX 15
#define N_TESTS 11

char *ft_strcpy(char *dest, char *src);
char *ft_strncpy(char *dest, char *src, unsigned int n);
int ft_str_is_alpha(char *str);
int ft_str_is_numeric(char *str);
int ft_str_is_lowercase(char *str);
int ft_str_is_uppercase(char *str);
int ft_str_is_printable(char *str);

int main()
{
    char *strs[N_TESTS];
    strs[0] = "Hello, World!";
    strs[1] = "HELLO";
    strs[2] = "\0empty?\0";
    strs[3] = "before\0after";
    strs[4] = "";
    strs[5] = "***...***";
    strs[6] = "0123456789";
    strs[7] = "0123456789-";
    strs[8] = "  \t..";
    strs[9] = "....!!!";
    strs[10] = "\r";

    char dest[2][30];

    int n_tests = 0, n_success = 0;

    printf("\nTest 00 start=======================================\n\n");
    n_tests = 0, n_success = 0;
    for (int i = 0; i < N_TESTS; i++)
    {
        memset(dest[0], '\0', sizeof(dest[0]));
        memset(dest[1], '\0', sizeof(dest[1]));
        strcpy(dest[0], strs[i]);
        ft_strcpy(dest[1], strs[i]);

        n_tests++;
        if (strcmp(dest[0], dest[1]) == 0)
        {
            // printf("=====================================> SUCCESS\n");
            n_success++;
        }
        else
        {
            printf("FAILURE:\n");
            printf("Reference:");
            printf("%s\n", dest[0]);
            printf("Custom:");
            printf("%s\n", dest[1]);
        }
    }
    printf("==> Success %d, Failure %d, Total %d\n", n_success, n_tests - n_success, n_tests);

    printf("\nTest 01 start=======================================\n\n");
    n_tests = 0, n_success = 0;
    for (int i = 0; i < N_TESTS; i++)
    {
        for (int n = 0; n < L_MAX; n++)
        {
            memset(dest[0], '\0', sizeof(dest[0]));
            memset(dest[1], '\0', sizeof(dest[1]));
            strncpy(dest[0], strs[i], n);
            ft_strncpy(dest[1], strs[i], n);

            n_tests++;
            if (strcmp(dest[0], dest[1]) == 0)
            {
                // printf("=====================================> SUCCESS\n");
                n_success++;
            }
            else
            {
                printf("=====================================> FAILURE\n");
                printf("strncpy(dest, strs, %d)\n", n);
                printf("Reference:");
                printf("%s\n", dest[0]);
                printf("Custom:");
                printf("%s\n", dest[1]);
            }
        }
    }
    printf("==> Success %d, Failure %d, Total %d\n", n_success, n_tests - n_success, n_tests);

    printf("\nTest 02 start=======================================\n\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        printf("%s", strs[i]);
        if (ft_str_is_alpha(strs[i]))
            printf(" is alpha\n");
        else
            printf(" is not alpha\n");
    }

    printf("\nTest 03 start=======================================\n\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        printf("%s", strs[i]);
        if (ft_str_is_numeric(strs[i]))
            printf(" is numeric\n");
        else
            printf(" is not numeric\n");
    }

    printf("\nTest 04 start=======================================\n\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        printf("%s", strs[i]);
        if (ft_str_is_lowercase(strs[i]))
            printf(" is lowercase\n");
        else
            printf(" is not lowercase\n");
    }

    printf("\nTest 05 start=======================================\n\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        printf("%s", strs[i]);
        if (ft_str_is_uppercase(strs[i]))
            printf(" is uppercase\n");
        else
            printf(" is not uppercase\n");
    }

    printf("\nTest 06 start=======================================\n\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        printf("%s", strs[i]);
        if (ft_str_is_printable(strs[i]))
            printf(" is printable\n");
        else
            printf(" is not printable\n");
    }

    return 0;
}