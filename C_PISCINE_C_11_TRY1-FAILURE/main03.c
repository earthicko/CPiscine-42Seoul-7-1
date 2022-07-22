#include <stdio.h>

int ft_count_if(char **tab, int length, int (*f)(char *));

int func(char *str) {
    if (str[0] == 'a') return (1);
    return (0);
}

int main() {
    char *strs[3];
    strs[0] = "abc";
    strs[1] = "bbc";
    strs[2] = "aab";

    int counted = ft_count_if(strs, 3, func);

    printf("%d\n", counted);

    return 0;
}