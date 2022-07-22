#include <stdio.h>

int *ft_range(int min, int max);

int main()
{
    printf("Test 01 ft_range======================================\n");
    for (int s = -5; s < 5; s++)
    {
        for (int e = -5; e < 5; e++)
        {
            printf("ft_range(%d, %d): ", s, e);
            int *arr = ft_range(s, e);
            if (arr == NULL)printf("Got NULL");
            for (int i = 0; i < e - s; i++)
            {
                printf("[%d]: %d, ", i, arr[i]);
            }
            printf("\n");
        }
    }
    printf("Test 01 ft_range======================================\n");
}