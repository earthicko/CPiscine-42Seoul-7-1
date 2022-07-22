#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);
int ft_atoi_base(char *str, char *base);

int main()
{
    char *nbrs[] =
        {
            "--+-10029783",
            "  \t\t --A0098",
            "+",
            "+ +1",
            "--0",
            "9B",
            "000000B",
            "08898X",
            "2147483647",
            "7FFFFFFF",
            "1111111111111111111111111111111",
            "-2147483648",
            "-80000000",
            "-10000000000000000000000000000000"};

    char *base[] =
        {
            "0123456789",
            "0123456789ABCDEF",
            "01",
            "X",
            "AB",
            " ",
            "ABC+",
            "ABC "};

    int N_NBR = sizeof(nbrs) / sizeof(nbrs[0]);
    int N_BASE = sizeof(base) / sizeof(base[0]);

    int counter = 0;
    printf("Start from [i]th test: ");
    int skip = 0;
    scanf("%d", &skip);
    for (int i_nbr = 0; i_nbr < N_NBR; i_nbr++)
    {
        for (int i_base_from = 0; i_base_from < N_BASE; i_base_from++)
        {
            for (int i_base_to = 0; i_base_to < N_BASE; i_base_to++)
            {
                if (counter >= skip)
                {
                    char *converted = ft_convert_base(nbrs[i_nbr], base[i_base_from], base[i_base_to]);
                    (void) converted;
                    printf("%d] Convert :%s:\tbase from :%s: to :%s:\n", counter, nbrs[i_nbr], base[i_base_from], base[i_base_to]);
                    printf("\tatoi result :%d:\n", ft_atoi_base(nbrs[i_nbr], base[i_base_from]));
                    printf("\tfinal result:%s:\n", converted);
                    printf("\n");
                    printf("Press ENTER to continue...");
                    getchar();
                }
                counter++;
            }
        }
    }

    return 0;
}