#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int cmp(int a, int b)
{
	if (a > b)
		return 1;
	if (a == b)
		return 0;
	return -1;
}

int main()
{
	int arr[5] = {5, 3, 2, 1, 39};
	printf("is_sort: %d\n", ft_is_sort(arr, 5, cmp));
	return 0;
}