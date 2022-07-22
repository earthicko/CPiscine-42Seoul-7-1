#include "./ex03/ft_point.h"
#include <unistd.h>

void set_point(t_point *point)
{
    point->x = 42;
    point->y = 21;
}

int main(void)
{
    write(1, "", 1);
    t_point point;
    set_point(&point);
    return 0;
}