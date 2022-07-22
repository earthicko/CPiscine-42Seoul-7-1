#include <stdio.h>
#include <limits.h>

int	ft_find_next_prime(int nb);
int	ft_ten_queens_puzzle(void);

int main()
{
	int	tc[20] = {
		-2,
		-1,
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		10,
		100,
		345,
		98765,
		99999999,
		INT_MAX,
		INT_MIN,
		INT_MIN + 1
	};

	for (int index = 0; index < 17; index++)
	{
		printf("find_next_prime(%d) = %d\n", tc[index], ft_find_next_prime(tc[index]));
	}
	for(int i=-5;i<50;i++)printf("find_next_prime(%d) = %d\n", i, ft_find_next_prime(i));
	printf("Start ten queen\n");
	printf("res: %d cases\n", ft_ten_queens_puzzle());

	return 0;
}
