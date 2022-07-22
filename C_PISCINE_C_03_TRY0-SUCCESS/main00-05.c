#include <stdio.h>
#include <string.h>

#define L_MAX 100
#define N_TESTS 12

// #define VERBOSE

int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, unsigned int nb);
char *ft_strstr(char *str, char *to_find);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
    char *p_strs[N_TESTS];
    p_strs[0] = "Hello, World!";
    p_strs[1] = "HELLO";
    p_strs[2] = "c Is tHE bEst";
    p_strs[3] = "salut, comment tu vas ? 42mots quarante-deux; ";
    p_strs[4] = "\0empty?\0";
    p_strs[5] = "before\0after";
    p_strs[6] = "";
    p_strs[7] = "empty";
    p_strs[8] = ", Wo";
    p_strs[9] = "vas ?";
    p_strs[10] = "ore\0af";
    p_strs[11] = " ";

    char strs[N_TESTS][L_MAX];
    for (int i = 0; i < N_TESTS; i++)
        strcpy(strs[i], p_strs[i]);

    char dest[2][L_MAX];

    int n_tests = 0, n_success = 0;

    printf("\nTest 00                                                      ft_strcmp\n\n");
    n_tests = 0, n_success = 0;
    for (int i = 0; i < N_TESTS; i++)
    {
        for (int j = 0; j < N_TESTS; j++)
        {
            n_tests++;
            int res_ref = strcmp(strs[i], strs[j]);
            int res_cus = ft_strcmp(strs[i], strs[j]);

#ifdef VERBOSE
            printf("ref %d vs cus %d\n", res_ref, res_cus);
#endif
            if (res_ref == res_cus)
            {
#ifdef VERBOSE
                printf("SUCCESS\n");
#endif
                n_success++;
            }
            else
            {
                printf("FAILURE while strcmp(%s,%s)\n", strs[i], strs[j]);
                printf("Reference:%d\n", res_ref);
                printf("Custom   :%d\n", res_cus);
            }
        }
    }
    printf("==> Success %d, Failure %d, Total %d\n", n_success, n_tests - n_success, n_tests);

    printf("\nTest 01                                                      ft_strncmp\n\n");
    n_tests = 0, n_success = 0;
    for (int i = 0; i < N_TESTS; i++)
    {
        for (int j = 0; j < N_TESTS; j++)
        {
            size_t i_len = strlen(strs[i]);
            size_t j_len = strlen(strs[j]);
            size_t max_len = (i_len > j_len) ? i_len : j_len;
            for (size_t lim = 0; lim < max_len; lim++)
            {
                n_tests++;
                int res_ref = strncmp(strs[i], strs[j], lim);
                int res_cus = ft_strncmp(strs[i], strs[j], lim);
#ifdef VERBOSE
                printf("ref %d vs cus %d\n", res_ref, res_cus);
#endif
                if (res_ref == res_cus)
                {
#ifdef VERBOSE
                    printf("SUCCESS\n");
#endif
                    n_success++;
                }
                else
                {
                    printf("FAILURE while strncmp(%s,%s,%zx)\n", strs[i], strs[j], lim);
                    printf("Reference:%d\n", res_ref);
                    printf("Custom   :%d\n", res_cus);
                }
            }
        }
    }
    printf("==> Success %d, Failure %d, Total %d\n", n_success, n_tests - n_success, n_tests);

    printf("\nTest 02                                                      ft_strcat\n\n");
    n_tests = 0, n_success = 0;
    for (int i = 0; i < N_TESTS; i++)
    {
        for (int j = 0; j < N_TESTS; j++)
        {
            strncpy(dest[0], strs[i], sizeof(dest[0]) / sizeof(dest[0][0]));
            strncpy(dest[1], strs[i], sizeof(dest[1]) / sizeof(dest[1][0]));

            n_tests++;
            strcat(dest[0], strs[j]);
            ft_strcat(dest[1], strs[j]);
#ifdef VERBOSE
            printf("ref %s vs cus %s\n", dest[0], dest[1]);
#endif
            if (strncmp(dest[0], dest[1], L_MAX * sizeof(char)) == 0)
            {
#ifdef VERBOSE
                printf("SUCCESS\n");
#endif
                n_success++;
            }
            else
            {
                printf("FAILURE while strcat(%s,%s)\n", strs[i], strs[j]);
                printf("Reference:%s\n", dest[0]);
                printf("Custom   :%s\n", dest[1]);
            }
        }
    }
    printf("==> Success %d, Failure %d, Total %d\n", n_success, n_tests - n_success, n_tests);

    printf("\nTest 03                                                      ft_strncat\n\n");
    n_tests = 0, n_success = 0;
    for (int i = 0; i < N_TESTS; i++)
    {
        for (int j = 0; j < N_TESTS; j++)
        {
            size_t i_len = strlen(strs[i]);
            size_t j_len = strlen(strs[j]);
            size_t max_len = (i_len > j_len) ? i_len : j_len;
            for (size_t lim = 0; lim < max_len; lim++)
            {
                strncpy(dest[0], strs[i], sizeof(dest[0]) / sizeof(dest[0][0]));
                strncpy(dest[1], strs[i], sizeof(dest[1]) / sizeof(dest[1][0]));

                n_tests++;
                strncat(dest[0], strs[j], lim);
                ft_strncat(dest[1], strs[j], lim);

#ifdef VERBOSE
                printf("ref %s vs cus %s\n", dest[0], dest[1]);
#endif
                if (strncmp(dest[0], dest[1], L_MAX * sizeof(char)) == 0)
                {
#ifdef VERBOSE
                    printf("SUCCESS\n");
#endif
                    n_success++;
                }
                else
                {
                    printf("FAILURE while strncat(%s,%s,%zx)\n", strs[i], strs[j], lim);
                    printf("Reference:%s\n", dest[0]);
                    printf("Custom   :%s\n", dest[1]);
                }
            }
        }
    }
    printf("==> Success %d, Failure %d, Total %d\n", n_success, n_tests - n_success, n_tests);

    printf("\nTest 04                                                      ft_strstr\n\n");
    n_tests = 0, n_success = 0;
    for (int i = 0; i < N_TESTS; i++)
    {
        for (int j = 0; j < N_TESTS; j++)
        {
            char *ref, *cus;
            n_tests++;
            ref = strstr(strs[i], strs[j]);
            cus = ft_strstr(strs[i], strs[j]);
#ifdef VERBOSE
            printf("ref %p vs cus %p\n", ref, cus);
#endif
            if (ref == cus)
            {
#ifdef VERBOSE
                printf("SUCCESS\n");
#endif
                n_success++;
            }
            else
            {
                printf("FAILURE while strstr(%s,%s)\n", strs[i], strs[j]);
                printf("str:%s:to_find:%s\n", strs[i], strs[j]);
                printf("Reference:%p", ref);
                if (ref != NULL)
                    printf(":%c\n", *ref);
                else
                    printf(":segfault\n");
                printf("Custom   :%p", cus);
                if (cus != NULL)
                    printf(":%c\n", *cus);
                else
                    printf(":segfault\n");
            }
        }
    }
    printf("==> Success %d, Failure %d, Total %d\n", n_success, n_tests - n_success, n_tests);

    printf("\nTest 05                                                      ft_strlcat\n\n");
    n_tests = 0, n_success = 0;
    for (int i = 0; i < N_TESTS; i++)
    {
        for (int j = 0; j < N_TESTS; j++)
        {
            size_t i_len = strlen(strs[i]);
            size_t j_len = strlen(strs[j]);
            size_t max_len = (i_len > j_len) ? i_len : j_len;
            for (size_t lim = 0; lim < max_len; lim++)
            {
                unsigned int ref, cus;
                strncpy(dest[0], strs[i], sizeof(dest[0]) / sizeof(dest[0][0]));
                strncpy(dest[1], strs[i], sizeof(dest[1]) / sizeof(dest[1][0]));

                n_tests++;
                ref = strlcat(dest[0], strs[j], lim);
                cus = ft_strlcat(dest[1], strs[j], lim);
#ifdef VERBOSE
                printf("ref %u vs cus %u\n", ref, cus);
                printf("ref %s vs cus %s\n", dest[0], dest[1]);
#endif
                if (strncmp(dest[0], dest[1], L_MAX * sizeof(char)) == 0 && ref == cus)
                {
#ifdef VERBOSE
                    printf("SUCCESS\n");
                    printf("while strlcat:%s:%s:%zu\n", strs[i], strs[j], lim);
                    printf("len(dst)=%lu, len(src)=%lu\n", strlen(strs[i]), strlen(strs[j]));
                    printf("Reference:%u:%s\n", ref, dest[0]);
                    printf("Custom   :%u:%s\n", cus, dest[1]);
#endif
                    n_success++;
                }
                else
                {
                    printf("FAILURE while strlcat:%s:%s:%zu\n", strs[i], strs[j], lim);
                    printf("len(dst)=%lu, len(src)=%lu\n", strlen(strs[i]), strlen(strs[j]));
                    printf("Reference:%u:%s\n", ref, dest[0]);
                    printf("Custom   :%u:%s\n", cus, dest[1]);
                }
            }
        }
    }
    printf("==> Success %d, Failure %d, Total %d\n", n_success, n_tests - n_success, n_tests);

    return 0;
}