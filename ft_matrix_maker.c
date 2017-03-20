/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:59:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/20 17:49:30 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_matrix	*ft_initval(t_matrix *matrix, int dim, t_matrix *first, int i)
{
	int			subunit;

	subunit = 0;
	matrix->name = 'A' + i;
	matrix->dim = dim;
	matrix->pos = (t_pos*)malloc(sizeof(t_pos) * 4);
	((!matrix->pos) ? (ft_error()) : (matrix));
	while (subunit < 4)
	{
		matrix->pos[subunit].x = 0;
		matrix->pos[subunit].y = 0;
		subunit++;
	}
	matrix->first = first;
	matrix->next = NULL;
	return (matrix);
}

static t_matrix	*ft_initmatrix(t_matrix *matrix, int piece_nb)
{
	int			i;
	int			dim;
	t_matrix	*first;

	i = 0;
	first = matrix;
	dim = ft_roundup_sqrt(4 * piece_nb);
	matrix->name = '@';
	while (i < piece_nb)
	{
		if (matrix->name != '@')
		{
			matrix->next = (t_matrix*)malloc(sizeof(t_matrix));
			matrix = matrix->next;
			((!matrix) ? (ft_error()) : (matrix));
		}
		matrix = ft_initval(matrix, dim, first, i);
		i++;
	}
	matrix = matrix->first;
	return (matrix);
}

static void		ft_checkchar(t_pos *pos, char c, int *x_pos, int *y_pos)
{
	if (c == '#')
	{
		pos->x = *x_pos;
		pos->y = *y_pos;
	}
	else if (c == '\n')
	{
		(*y_pos)--;
		(*x_pos) = -1;
	}
	else if (c != '.')
		ft_error();
}

static t_matrix	*ft_makeone(t_matrix *matrix, char *str, int *str_pos)
{
	int			x_pos;
	int			y_pos;
	int			subunit_nb;

	subunit_nb = 0;
	x_pos = 0;
	y_pos = 0;
	((*str_pos != 0) ? ((*str_pos)++) : (*str_pos));
	while (subunit_nb < 4 && str[*str_pos])
	{
		ft_checkchar(&(matrix->pos[subunit_nb]), str[*str_pos], &x_pos, &y_pos);
		((str[*str_pos] == '#') ? (subunit_nb++) : (subunit_nb));
		while (subunit_nb == 4 && str[*str_pos + 1] && \
			!(str[*str_pos] == '\n' && str[*str_pos + 1] == '\n'))
			(*str_pos)++;
		x_pos++;
		(*str_pos)++;
	}
	return (matrix);
}

t_matrix		*ft_matrix_maker(char *str, int piece_nb)
{
	int			str_pos;
	t_matrix	*matrix;

	str_pos = 0;
	(!(matrix = (t_matrix*)malloc(sizeof(t_matrix))) ? (ft_error()) : (matrix));
	matrix = ft_initmatrix(matrix, piece_nb);
	while (str[str_pos])
	{
		matrix = ft_makeone(matrix, str, &str_pos);
		(((!str[str_pos] && matrix->next) || (str[str_pos] && !matrix->next)) ?\
			(ft_error()) : (matrix));
		((matrix->next) ? (matrix = matrix->next) : (matrix));
	}
	matrix = matrix->first;
	return (matrix);
}
