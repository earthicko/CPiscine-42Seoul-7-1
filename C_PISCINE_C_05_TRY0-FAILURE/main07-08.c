#include <stdio.h>

int	ft_find_next_prime(int nb);
int	ft_ten_queens_puzzle(void);

int main()
{
	for (int index = -2; index <= 20; index++)
	{
		printf("find_next_prime(%d) = %d\n", index, ft_find_next_prime(index));
	}
	printf("Start ten queen\n");
	printf("res: %d cases\n", ft_ten_queens_puzzle());

	return 0;
}
