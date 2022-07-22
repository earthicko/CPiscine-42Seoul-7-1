#include <stdio.h>
#include "./ex07/ft_putnbr.c"

int	main(void)
{
	ft_putnbr(100);
	printf("==100\n");
	ft_putnbr(123);
	printf("==123\n");
	ft_putnbr(1000012988);
	printf("==1000012988\n");
	ft_putnbr(2147483647);
	printf("==2147483647\n");
	ft_putnbr(-2147483648);
    printf("==-2147483648\n");
	ft_putnbr(-1009);
	printf("==-1009\n");
	ft_putnbr(0);
	printf("==0\n");
	printf("==Test 07 end\n");

	return 0;
}
