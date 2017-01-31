/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:44:08 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/28 15:47:33 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_m_xplus(t_matrix *matrix, int num)
{
	int		subunit;
	int		end;

	subunit = 0;
	end = 0;
	while (end == 0 && matrix && subunit < 4)
	{
		((matrix->pos[subunit].x + num >= 0 && matrix->pos[subunit].x + num <=
			matrix->dim) ? (subunit++) : (end = 1));
	}
	((num < 0 && end == 1) ? (ft_m_xplus(matrix, num + 1)) : num);
	((num > 0 && end == 1) ? (ft_m_xplus(matrix, num - 1)) : num);
	if (subunit == 4)
	{
		while (subunit > 0)
		{
			matrix->pos[subunit].x += num;
			subunit--;
		}
	}
	return (end);
}

static int		ft_m_yplus(t_matrix *matrix, int num)
{
	int		subunit;
	int		end;

	subunit = 0;
	end = 0;
	while (end == 0 && matrix && subunit < 4)
	{
		((matrix->pos[subunit].y + num <= 0 && matrix->pos[subunit].y + num >=
			matrix->dim) ? (subunit++) : (end = 1));
	}
	((num < 0 && end == 1) ? (ft_m_yplus(matrix, num + 1)) : num);
	((num > 0 && end == 1) ? (ft_m_yplus(matrix, num - 1)) : num);
	if (subunit == 4)
	{
		while (subunit > 0)
		{
			matrix->pos[subunit].y += num;
			subunit--;
		}
	}
	return (end);
}

int			ft_m_plus(t_matrix *matrix, int num, char axis)
{
	int		ret;

	ret = 1;
	if (axis == 'x' || axis == 'X')
		ret = ft_m_xplus(matrix, num);
	else if (axis == 'y' || axis == 'Y')
		ret = ft_m_yplus(matrix, num);
	else
		ft_error("addition failed: unknown axis");
	return (ret);
}
