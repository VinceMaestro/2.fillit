/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:53:33 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/27 19:39:02 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printmap(t_map map, int dim)
{
	int		x_;
	int		y_;

	y_ = 0;
	ft_putstr("\tmap :\n");
	while (y_ < dim)
	{
		x_ = 0;
		ft_putstr("\t\t( ");
		while (x_ < dim)
		{
			ft_putnbr(map.axis[x_][y_]);
			ft_putchar(' ');
			x_++;
		}
		ft_putstr(")\n");
		y_++;
	}
}
