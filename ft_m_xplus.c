/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_xplus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 02:47:26 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/22 17:49:10 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*ft_m_xplus(t_matrix *matrix, int num)
{
	int		subunit;
	int		end;

	subunit = 0;
	end = 0;
	while (end == 0 && matrix && subunit < 4)
	{
		((matrix->pos[subunit].x + num >= 0 && matrix->pos[subunit].x +
			num < matrix->dim) ? (subunit++) : (end = 1));
	}
	if (end == 1 && num < -1)
		return (matrix = ft_m_xplus(matrix, num + 1));
	else if (end == 1 && num > 1)
		return (matrix = ft_m_xplus(matrix, num - 1));
	else if (end == 0 && subunit == 4)
	{
		subunit = 0;
		while (subunit < 4)
		{
			matrix->pos[subunit].x += num;
			subunit++;
		}
	}
	return (matrix);
}
