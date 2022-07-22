#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_TESTS 9

char **ft_split(char *str, char *charset);

int main()
{
    char *str_sep[10][2] =
        {
            {"Common sentence with spaces.", " "},
            {"**Separa**te*d by **asterisks*", "**"},
            {"Separation by abc", "abc"},
            {"No separation", "\0"},
            {"abc separation", "abc\0def"},
            {"\0", "!!!"},
            {"aaaaaaaaa", "a"},
            {"a^b!cde$f$$g^hijklm#nopqrstuvwxyz", "!@#$^&"},
            {"", ""}
        };

    printf("Test 05 ft_split======================================\n");
    for (int i = 0; i < N_TESTS; i++)
    {
        printf("Split :%s: with :%s:\n", str_sep[i][0], str_sep[i][1]);
        char **splitted = ft_split(str_sep[i][0], str_sep[i][1]);
        while (*splitted)
            printf("\t:%s:\n", *splitted++);
    }
    printf("Test 05 ft_split======================================\n");
    return 0;
}