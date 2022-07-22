#include <stdio.h>
#include <limits.h>

int ft_strlen(char *str);
void ft_putstr(char *str);
void ft_putnbr(int nb);
int ft_atoi(char *str);
void ft_putnbr_base(int nbr, char *base);
int ft_atoi_base(char *str, char *base);

int main()
{
	char *strs[10];
	strs[0] = "  ---+--+1234ab567";
	strs[1] = "--1";
	strs[2] = "\t\t  -";
	strs[3] = "8b";
	strs[4] = "++-00000000077";
	strs[5] = "9000+";
	strs[6] = "";
	strs[7] = "iffnpoonov";
	strs[8] = "\r  \t --+-0089B7A";
	strs[9] = "X";

	char *base[10];
	base[0] = "0123456789";
	base[1] = "01";
	base[2] = "0123456789ABCDEF";
	base[3] = "poneyvif";
	base[4] = "0123\t56789";
	base[5] = "ABCDEFGHIJ\t";
	base[6] = "plus+";
	base[7] = "Hi, nice to meet you";
	base[8] = "";
	base[9] = "minus-in-the-middle";

	int nbrs[10] = {0, -10, 81772, INT_MAX, INT_MIN};

	printf("Test 00 ================================================ ft_strlen\n");
	for (int i = 0; i < 10; i++)
	{
		printf("strlen of :%s: == %d\n", strs[i], ft_strlen(strs[i]));
	}
	printf("Test 00 ====================================================== end\n");

	printf("Test 01 ================================================ ft_putstr\n");
	for (int i = 0; i < 10; i++)
	{
		printf("put :%s:", strs[i]);
		fflush(stdout);
		ft_putstr(strs[i]);
		printf("\n");
	}
	printf("Test 01 ====================================================== end\n");

	printf("Test 02 ================================================ ft_putnbr\n");
	for (int i = 0; i < 10; i++)
	{
		printf("put :%d:", nbrs[i]);
		fflush(stdout);
		ft_putnbr(nbrs[i]);
		printf("\n");
	}
	printf("Test 02 ====================================================== end\n");

	printf("Test 03 ================================================== ft_atoi\n");
	for (int i = 0; i < 10; i++)
	{
		printf("atoi :%s:%d\n", strs[i], ft_atoi(strs[i]));
	}
	printf("Test 03 ====================================================== end\n");

	printf("Test 04 =========================================== ft_putnbr_base\n");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("putnbr_base :%d:%s:", nbrs[i], base[j]);
			fflush(stdout);
			ft_putnbr_base(nbrs[i], base[j]);
			printf("\n");
		}
	}
	printf("Test 04 ====================================================== end\n");

	printf("Test 05 ============================================== ft_atoi_base\n");
	{
		int tc[18][2] = {
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0},
			{5, 0},
			{8, 0},
			{9, 0},
			{1, 1},
			{0, 2},
			{0, 3},
			{7, 3},
			{0, 4},
			{0, 5},
			{1, 6},
			{6, 7},
			{6, 8},
			{5, 9},
		};
		for (int i = 0; i < 18; i++)
		{
			printf("atoi_base :%s:%s:%d\n", strs[tc[i][0]], base[tc[i][1]], ft_atoi_base(strs[tc[i][0]], base[tc[i][1]]));
		}
	}
	printf("Test 05 ====================================================== end\n");

	return 0;
}
