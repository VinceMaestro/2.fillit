/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:59:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/01 03:51:38 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_matrix	*ft_init_newmatrix(t_matrix *matrix)
{
	matrix = ft_getmatrix(matrix, LAST);
	matrix->next = (t_matrix*)malloc(sizeof(t_matrix));
	(!(matrix->next) ? (ft_error("FAILED : malloc new matrix")) : (matrix));
	matrix->next->name = matrix->name + 1;
	matrix->next->first = matrix->first;
	matrix = matrix->next;
	matrix->pos = (t_pos*)malloc(sizeof(t_pos) * 4);
	if (!matrix->pos)
		ft_error("Failed Malloc Pos new matrix");
	matrix->next = NULL;
	return (matrix);
}

static t_matrix	*ft_init_firstmatrix(t_matrix *matrix)
{
	matrix->first = matrix;
	matrix->name = 'A';
	matrix->pos = (t_pos*)malloc(sizeof(t_pos) * 4);
	if (!matrix->pos)
		ft_error("Failed Malloc Pos first matrix");
	matrix->next = NULL;
	return (matrix);
}

static t_matrix	*ft_initmatrix(t_matrix *matrix, int dim)
{
	int			i;

	i = 0;
	if (matrix->first)
		matrix = ft_init_newmatrix(matrix);
	else
		matrix = ft_init_firstmatrix(matrix);
	matrix->dim = dim;
	while (i < 4)
	{
		matrix->pos[i].x = 0;
		matrix->pos[i].y = 0;
		i++;
	}
	return (matrix);
}

t_matrix		*ft_matrix_maker(char *str, int dim)
{
	int			x_pos;
	int			y_pos;
	int			subunit_nb;
	int			str_pos;
	t_matrix	*matrix;

	str_pos = 0;
	matrix = (t_matrix*)malloc(sizeof(t_matrix));
	((!matrix) ? (ft_error("matrix creation failed")) : (matrix));
	matrix->first = NULL;
	while (str[str_pos])
	{
		matrix = ft_initmatrix(matrix, dim);
		subunit_nb = 0;
		x_pos = 0;
		y_pos = 0;
		((str_pos != 0) ? (str_pos++) : (str_pos));
		while (subunit_nb < 4 && str[str_pos])
		{
			if (str[str_pos] == '#')
			{
				(matrix)->pos[subunit_nb].x = x_pos;
				(matrix)->pos[subunit_nb].y = y_pos;
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
	}
	matrix = (matrix)->first;
	return (matrix);
}
