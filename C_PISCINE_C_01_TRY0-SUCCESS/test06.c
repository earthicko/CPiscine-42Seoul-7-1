#include <stdio.h>
#include <string.h>
#include "./ex06/ft_strlen.c"

int main()
{
    printf("===================================================================Test 06 start\n");
    int len;

    char *str0 = "Hello, World!\n";
    char *str1 = "\0empty";
    char *str2 = "099\t\t 94\n\nsadk";
    char *str3 = "null";
    char *str4 = "null in middle\0null after";
    char *str5 = "";

    len = ft_strlen(str0);
    printf("len of %s = %d\n", str0, len);
    printf("Should be %lu\n", strlen(str0));

    len = ft_strlen(str1);
    printf("len of %s = %d\n", str1, len);
    printf("Should be %lu\n", strlen(str1));

    len = ft_strlen(str2);
    printf("len of %s = %d\n", str2, len);
    printf("Should be %lu\n", strlen(str2));

    len = ft_strlen(str3);
    printf("len of %s = %d\n", str3, len);
    printf("Should be %lu\n", strlen(str3));

    len = ft_strlen(str4);
    printf("len of %s = %d\n", str4, len);
    printf("Should be %lu\n", strlen(str4));

    len = ft_strlen(str5);
    printf("len of %s = %d\n", str5, len);
    printf("Should be %lu\n", strlen(str5));

    printf("=====================================================================Test 06 end\n");
    return 0;
}