/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:17:43 by vpetit            #+#    #+#             */
/*   Updated: 2017/04/04 18:14:07 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_matrix	*ft_m_xplus(t_matrix *matrix, int num)
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

static t_matrix	*ft_m_yplus(t_matrix *matrix, int num)
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

static t_matrix	*ft_m_prev(t_matrix *matrix)
{
	t_matrix	*current;

	current = matrix;
	matrix = matrix->first;
	while (matrix->next != current && matrix != current)
		matrix = matrix->next;
	return (matrix);
}

static t_matrix	*ft_m_increasedim(t_matrix *matrix)
{
	while (matrix)
	{
		matrix->dim += 1;
		if (!matrix->next)
			return (matrix = matrix->first);
		matrix = matrix->next;
	}
	ft_error();
	return (NULL);
}

t_matrix		*ft_m_op(char *arg, t_matrix *matrix, int num)
{
	if (*arg == 'X' || *arg == 'x')
		return (ft_m_xplus(matrix, num));
	else if (*arg == 'Y' || *arg == 'y')
		return (ft_m_yplus(matrix, num));
	else if (!ft_strcmp(arg, "prev"))
		return (ft_m_prev(matrix));
	else if (!ft_strcmp(arg, "incrdim"))
		return (ft_m_increasedim(matrix));
	ft_error();
	return (NULL);
}
