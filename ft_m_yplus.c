/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_yplus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:44:08 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/10 18:15:04 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*ft_m_yplus(t_matrix *matrix, int num)
{
	int		subunit;
	int		end;

	subunit = 0;
	end = 0;
	while (end == 0 && matrix && subunit < 4)
	{
		((matrix->pos[subunit].y + num <= 0 && matrix->pos[subunit].y +
			num > -matrix->dim) ? (subunit++) : (end = 1));
	}
	if (end == 1 && num < -1)
		return (matrix = ft_m_yplus(matrix, num + 1));
	else if (end == 1 && num > 1)
		return (matrix = ft_m_yplus(matrix, num - 1));
	else if (end == 0 && subunit == 4)
	{
		subunit = 0;
		while (subunit < 4)
		{
			matrix->pos[subunit].y += num;
			subunit++;
		}
	}
	return (matrix);
}
