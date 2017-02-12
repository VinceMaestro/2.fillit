
#include "fillit.h"

void	ft_printmap(t_map map, int dim)
{
    int     x_;
    int     y_;

    x_ = 0;
    ft_putstr("\tmap :\n");
    while (x_ < dim)
    {
        y_ = 0;
        ft_putstr("\t\t( ");
        while (y_ < dim)
        {
            ft_putnbr(map.x[x_][y_]);
            ft_putchar(' ');
            y_++;
        }
        ft_putstr(")\n");
        x_++;
    }
}
