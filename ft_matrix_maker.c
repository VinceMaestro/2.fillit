/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:59:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/25 17:11:53 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_initmatrix(t_matrix *matrix, int dim)
{
	if (matrix != ft_getmatrix(matrix, LAST))
	{
		matrix->next = (t_matrix*)malloc(sizeof(t_matrix));
		(!(matrix->next) ? (ft_error("FAILED : malloc new")) : (matrix));
		matrix->next->name = matrix->name + 1;
		matrix->next->first = matrix->first;
		matrix = matrix->next;
	}
	else
	{
		matrix->first = matrix;
		matrix->name = 'A';
	}
	matrix->pos = (t_pos*)malloc(sizeof(t_pos) * 4);
	(!(matrix->pos) ? (ft_error("FAILED : malloc pos")) : (matrix));
	matrix->dim = dim;
	matrix->next = NULL;
	matrix->pos->x = 0;
	matrix->pos->y = 0;
	matrix->pos->z = 1;
	matrix = matrix->first;
}

static int		ft_getmatrix(t_matrix *matrix, char name)
{
	if (matrix)
	{
		while (matrix->next && matrix->name != name)
			matrix = matrix->next;
		if (matrix->name == name)
			return (1);
	}
	return (0);
}

t_matrix		*ft_matrix_maker(char *str, int dim)
{
	int			x_pos;
	int			y_pos;
	int			subunit_nb;
	int			str_pos;
	t_matrix	*matrix;

	str_pos = 0;
	while (str[str_pos + 1])
	{
		matrix = (t_matrix*)malloc(sizeof(t_matrix));
		((!matrix) ? (ft_error("matrix creation failed")) : (matrix));
		ft_initmatrix(matrix, dim);
		subunit_nb = 0;
		x_pos = 0;
		y_pos = 0;
		while (subunit_nb < 3 && str[str_pos])
		{
			if (str[str_pos] == '#')
			{
				matrix->pos[subunit_nb]->x = x_pos++;
				matrix->pos[subunit_nb++]->y = y_pos;
				// x_pos++;
				// subunit_nb++;
			}
			else if (str[str_pos] == '\n')
			{
				y_pos--;
				x_pos = 0;
			}
			else if (str[str_pos] != '.')
				ft_error("input error");
			str_pos++;
		}
		matrix = matrix->next;
	}
	matrix = matrix->first;
	return (matrix);
}
