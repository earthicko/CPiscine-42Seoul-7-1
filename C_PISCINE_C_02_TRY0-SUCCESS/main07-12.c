#include <stdio.h>
#include <string.h>

#define L_MAX 100
#define N_TESTS 11

char *ft_strupcase(char *str);
char *ft_strlowcase(char *str);
char *ft_strcapitalize(char *str);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
void ft_putstr_non_printable(char *str);
void *ft_print_memory(void *addr, unsigned int size);

int main()
{
    char *strs[N_TESTS];
    strs[0] = "Hello, World!";
    strs[1] = "HELLO";
    strs[2] = "c Is tHE bEst";
    strs[3] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    strs[4] = "\0empty?\0";
    strs[5] = "before\0after";
    strs[6] = "";
    strs[7] = "***...***";
    strs[8] = "0123456789-";
    strs[9] = "  \t.\e.abc\adef\b\x18yes\v";
    // expect   \09.\1b.abc\07def\08\18yes\0b
    strs[10] = "Coucou\ntu vas bien ?";

    char dest[2][L_MAX];

    int n_tests = 0, n_success = 0;

    printf("\nTest 07 start=======================================\n\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        memset(dest[0], '\0', sizeof(dest[0]));
        strcpy(dest[0], strs[i]);
        printf("Before         :");
        printf("%s\n", dest[0]);
        printf("After strupcase:");
        ft_strupcase(dest[0]);
        printf("%s\n", dest[0]);
    }

    printf("\nTest 08 start=======================================\n\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        memset(dest[0], '\0', sizeof(dest[0]));
        strcpy(dest[0], strs[i]);
        printf("Before          :");
        printf("%s\n", dest[0]);
        printf("After strlowcase:");
        ft_strlowcase(dest[0]);
        printf("%s\n", dest[0]);
    }

    printf("\nTest 09 start=======================================\n\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        memset(dest[0], '\0', sizeof(dest[0]));
        strcpy(dest[0], strs[i]);
        printf("Before             :");
        printf("%s\n", dest[0]);
        printf("After strcapitalize:");
        ft_strcapitalize(dest[0]);
        printf("%s\n", dest[0]);
    }

    printf("\nTest 10 start=======================================\n\n");
    n_tests = 0, n_success = 0;
    for (int i = 0; i < N_TESTS; i++)
    {
        for (int n = 0; n < L_MAX; n += 10)
        {
            int test_strcmp_res, test_return_val_res;
            size_t n_ref, n_custom;

            memset(dest[0], '\0', sizeof(dest[0]));
            memset(dest[1], '\0', sizeof(dest[1]));

            n_ref = strlcpy(dest[0], strs[i], n);
            n_custom = ft_strlcpy(dest[1], strs[i], n);

            test_strcmp_res = strcmp(dest[0], dest[1]) == 0;
            test_return_val_res = n_ref == n_custom;

            n_tests++;

            if (!test_strcmp_res || !test_return_val_res)
            {
                printf("test str:%s:n:%d\n", strs[i], n);
                if (test_strcmp_res)
                    printf("==========================> strcmp SUCCESS");
                else
                    printf("==========================> strcmp FAILURE");
                if (test_return_val_res)
                    printf(", return val SUCCESS\n");
                else
                    printf(", return val FAILURE\n");
                printf("strlcpy(dest, strs, %d)\n", n);
                printf("Reference:");
                printf("[%zu]:%s\n", n_ref, dest[0]);
                printf("Custom:");
                printf("[%zu]:%s\n", n_custom, dest[1]);
                printf("test str:%s:n:%d\n", strs[i], n);
            }
            else
                n_success++;
        }
    }
    printf("==> Success %d, Failure %d, Total %d\n", n_success, n_tests - n_success, n_tests);

    printf("\nTest 11 start=======================================\n\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        printf("input str              :%s\n", strs[i]);
        printf("ft_putstr_non_printable:");
        fflush(stdout);
        ft_putstr_non_printable(strs[i]);
        printf("\n");
    }

    printf("\nTest 12 start=======================================\n\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        for (int n = 0; n < L_MAX; n += 11)
        {
            printf("n:%d:input str:%s\n", n, strs[i]);
            fflush(stdout);
            ft_print_memory(strs[i], n);
            printf("\n");
        }
    }

    return 0;
}