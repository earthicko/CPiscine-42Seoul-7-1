#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int main()
{
    printf("Test 02 ft_ultimate_range======================================\n");
    for (int s = -5; s < 5; s++)
    {
        for (int e = -5; e < 5; e++)
        {
            printf("ft_ultimate_range(%d, %d): ", s, e);
            int *arr;
            int width = ft_ultimate_range(&arr, s, e);
            if (arr == NULL) printf("Got NULL, ");
            printf("got %d elem, ", width);
            for (int i = 0; i < width; i++)
            {
                printf("[%d]: %d, ", i, arr[i]);
            }
            printf("\n");
        }
    }
    printf("Test 02 ft_ultimate_range======================================\n");

    return 0;
}