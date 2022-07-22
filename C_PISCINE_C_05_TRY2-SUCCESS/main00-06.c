#include <stdio.h>
#include <limits.h>

#define N_TC 20

int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_iterative_power(int nb, int power);
int	ft_recursive_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);

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
		25,
		36,
		100,
		345, 
		98765,
		119025,
		99999999,
		INT_MAX,
		INT_MIN,
		INT_MIN + 1
	};

	for (int i=-10;i<=10;i++)
	{
		printf("iter fac(%d) = %d\n", i, ft_iterative_factorial(i));
	}
	for (int i=-10;i<=10;i++)
	{
		printf("recur fac(%d) = %d\n", i, ft_recursive_factorial(i));
	}
	for (int base = -5;base <= 10; base++)
	{
		for (int power = -2; power <= 5; power++)
		{
			printf("iter %d ^ %d = %d\n", base, power, ft_iterative_power(base, power));
		}
	}
	for (int base = -5;base <= 10; base++)
	{
		for (int power = -2; power <= 5; power++)
		{
			printf("recur %d ^ %d = %d\n", base, power, ft_recursive_power(base, power));
		}
	}
	for (int index = -2; index <= 10; index++)
	{
		printf("fib(%d) = %d\n", index, ft_fibonacci(index));
	}
	for (int index = 0; index < N_TC; index++)
	{
		printf("sqrt(%d) = %d\n", tc[index], ft_sqrt(tc[index]));
	}
	for (int index = -5; index < 50; index++)
		printf("sqrt(%d) = %d\n", index, ft_sqrt(index));
	for (int index = -5; index < 50; index++)
		printf("is_prime(%d) = %d\n", index, ft_is_prime(index));
	for (int index = 0; index < N_TC; index++)
	{
		printf("is_prime(%d) = %d\n", tc[index], ft_is_prime(tc[index]));
	}

	return 0;
}
