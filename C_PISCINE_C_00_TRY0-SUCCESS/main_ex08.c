#include <stdio.h>
#include "./ex08/ft_print_combn.c"

int	main(void)
{
	for (int i=1;i<10;i++){
		ft_print_combn(i);
		printf("<== i = %d\n", i);
	}
	printf("==Test 08 end\n");

	return 0;
}
