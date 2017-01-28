/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 14:52:01 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/28 15:31:16 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printmatrix(t_matrix *matrix)
{
	int		subunit_nb;

	subunit_nb = 0;
	ft_putstr("MATRIX : \n");
	while (subunit_nb < 4)
	{
		ft_putstr("x = ");
		ft_putnbr(matrix->pos[subunit_nb].x);
		ft_putstr(", y = ");
		ft_putnbr(matrix->pos[subunit_nb].y);
		ft_putstr(" \n");
		subunit_nb++;
	}
}
