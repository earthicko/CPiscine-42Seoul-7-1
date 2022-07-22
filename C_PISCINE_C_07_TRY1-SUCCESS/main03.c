#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_STR 5
#define N_SEP 7

char *ft_strjoin(int size, char **strs, char *sep);

char *strcat_chain(int size, char **strs, char *sep)
{
    char *result = (char *)calloc(1000, sizeof(char));
    for (int i = 0; i < size; i++)
    {
        strcat(result, strs[i]);
        if (i < size - 1)
            strcat(result, sep);
    }
    return result;
}

int main()
{
    char *strs[10] =
        {
            "asdasd",
            "beforenull\0afternull",
            "\0",
            "\0after",
            ""};

    char *seps[10] =
        {
            "sep",
            "*",
            "",
            "beforenull\0afternull",
            "\0",
            "\0after",
            ""};

    printf("Test 03 ft_strjoin======================================\n");
    for (int size = 0; size <= N_STR; size++)
    {
        for (int i_sep = 0; i_sep < N_SEP; i_sep++)
        {
            char *joined_std = strcat_chain(size, strs, seps[i_sep]);
            char *joined_usr = ft_strjoin(size, strs, seps[i_sep]);
            if (strcmp(joined_std, joined_usr) != 0)
            {
                printf("Failure while joining ");
                for (int i=0;i<size;i++)printf(":%s: ", strs[i]);
                printf("\n");
                printf("\tstd::%s:\n", joined_std);
                printf("\tusr::%s:\n", joined_usr);
            }
            printf("Joined:[%d]:%s:\n", size, joined_usr);
            free(joined_std);
            free(joined_usr);
        }
    }
    printf("Test 03 ft_strjoin======================================\n");
    return 0;
}