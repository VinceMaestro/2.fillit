/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:59:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/22 17:13:38 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_matrix	*ft_checkshape(t_matrix *matrix)
{
	int		dim;
	int		subunit;

	dim = matrix->dim;
	subunit = 0;
	while (subunit < 4)
	{
		if (matrix->pos[subunit].x >= dim || matrix->pos[subunit].y >= dim)
		{
			matrix = matrix->first;
			matrix = ft_m_increasedim(matrix);
			return (ft_checkshape(matrix));
		}
		subunit++;
	}
	if (matrix->next)
		return (ft_checkshape(matrix->next));
	else
		return (matrix = matrix->first);
}

static t_matrix	*ft_initmatrix(t_matrix *matrix, int piece_nb)
{
	int			i;
	int			dim;
	int			subunit;
	t_matrix	*first;

	i = 0;
	first = matrix;
	dim = ft_roundup_sqrt(4 * piece_nb);
	matrix->name = '@';
	while (i < piece_nb)
	{
		subunit = 0;
		if (matrix->name != '@')
		{
			matrix->next = (t_matrix*)malloc(sizeof(t_matrix));
			matrix = matrix->next;
			((!matrix) ? (ft_error("ft_initmatrix: Alloc failed")) : (matrix));
		}
		matrix->name = 'A' + i;
		matrix->dim = dim;
		matrix->pos = (t_pos*)malloc(sizeof(t_pos) * 4);
		((!matrix->pos) ? (ft_error("ft_initmatrix: Alloc failed")) : (matrix));
		while (subunit < 4)
		{
			matrix->pos[subunit].x = 0;
			matrix->pos[subunit].y = 0;
			subunit++;
		}
		matrix->first = first;
		matrix->next = NULL;
		i++;
	}
	matrix = matrix->first;
	return (matrix);
}

t_matrix		*ft_matrix_maker(char *str, int piece_nb)
{
	int			x_pos;
	int			y_pos;
	int			subunit_nb;
	int			str_pos;
	t_matrix	*matrix;

	str_pos = 0;
	matrix = (t_matrix*)malloc(sizeof(t_matrix));
	((!matrix) ? (ft_error("matrix creation failed")) : (matrix));
	matrix = ft_initmatrix(matrix, piece_nb);
	while (str[str_pos])
	{
		subunit_nb = 0;
		x_pos = 0;
		y_pos = 0;
		((str_pos != 0) ? (str_pos++) : (str_pos));
		while (subunit_nb < 4 && str[str_pos])
		{
			if (str[str_pos] == '#')
			{
				matrix->pos[subunit_nb].x = x_pos;
				matrix->pos[subunit_nb].y = y_pos;
				subunit_nb++;
			}
			else if (str[str_pos] == '\n')
			{
				y_pos--;
				x_pos = -1;
			}
			else if (str[str_pos] != '.')
				ft_error("input error");
			while (subunit_nb == 4 && str[str_pos + 1] && \
				!(str[str_pos] == '\n' && str[str_pos + 1] == '\n'))
				str_pos++;
			x_pos++;
			str_pos++;
		}
		(((!str[str_pos] && matrix->next) || (str[str_pos] && !matrix->next)) ?\
			(ft_error("try to read to long buffer")) : (matrix));
		((matrix->next) ? (matrix = matrix->next) : (matrix));
	}
	matrix = matrix->first;
	if (piece_nb < 3)
		matrix = ft_checkshape(matrix);
	return (matrix);
}
