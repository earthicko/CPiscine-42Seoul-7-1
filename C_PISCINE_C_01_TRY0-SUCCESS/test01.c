#include <stdio.h>
#include "./ex01/ft_ultimate_ft.c"

int main()
{
    printf("===================================================================Test 01 start\n");
    int buffer = 0;
    int *p_buffer = &buffer;
    int **pp_buffer = &p_buffer;
    int ***ppp_buffer = &pp_buffer;
    int ****pppp_buffer = &ppp_buffer;
    int *****ppppp_buffer = &pppp_buffer;
    int ******pppppp_buffer = &ppppp_buffer;
    int *******ppppppp_buffer = &pppppp_buffer;
    int ********pppppppp_buffer = &ppppppp_buffer;
    int *********ppppppppp_buffer = &pppppppp_buffer;
printf("Before ft_ultimate_ft: %d\n", buffer);
    ft_ultimate_ft(ppppppppp_buffer);
    printf("After ft_ultimate_ft: %d\n", buffer);
    printf("should be: 42\n");
    printf("=====================================================================Test 01 end\n");
    return 0;
}