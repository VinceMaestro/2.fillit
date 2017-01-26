/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:59:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/26 16:13:32 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

static int		ft_getmatrix(t_matrix *matrix, char name)
{
	if (matrix)
	{
		// printf("matrix name is : %c \n", matrix->name);
		if (!matrix->next || !matrix->name || matrix->name == name)
			return (1);
		while (matrix->next && matrix->name != name)
		{
			printf("matrix next AAAAAAAAAAAAAAA\n");
			matrix = matrix->next;
		}
		if (matrix->name == name)
			return (1);
	}
	return (0);
}

static void		ft_initmatrix(t_matrix *matrix, int dim)
{
	int		i;

	i = 0;
	printf("initmatrix Start\n");
	(!(matrix) ? (ft_error("matrix creation failed")) : (matrix));
	ft_getmatrix(matrix, LAST);
	if (matrix->first)
	{
		matrix->next = (t_matrix*)malloc(sizeof(t_matrix));
		(!(matrix->next) ? (ft_error("FAILED : malloc new")) : (matrix));
		matrix->next->name = matrix->name + 1;
		matrix->next->first = matrix->first;
		matrix = matrix->next;
	}
	else
		matrix->first = matrix;
	(!(ft_isalpha(matrix->name)) ? (matrix->name = 'A') : (matrix->name));
	(!(matrix->pos) ? (matrix->pos = (t_pos*)malloc(sizeof(t_pos) * 4)) : matrix->pos);
	(!(matrix->pos) ? (ft_error("FAILED : malloc pos")) : (matrix));
	matrix->dim = dim;
	matrix->next = NULL;
	while (i < 4)
	{
		matrix->pos[i].x = 0;
		matrix->pos[i].y = 0;
		matrix->pos[i].z = 1;
		i++;
	}
	printf("initmatrix sucess name : %c\n", matrix->name);
}

t_matrix		*ft_matrix_maker(char *str, int dim)
{
	int			x_pos;
	int			y_pos;
	int			subunit_nb;
	int			str_pos;
	t_matrix	*matrix;

	str_pos = 0;
	printf("starting\n");
	matrix = (t_matrix*)malloc(sizeof(t_matrix));
	((!matrix) ? (ft_error("matrix creation failed")) : (matrix));
	matrix->pos = (t_pos*)malloc(sizeof(t_pos) * 4);
	(!(matrix->pos) ? (ft_error("FAILED : malloc pos")) : (matrix));
	matrix->first = matrix;
	while (str[str_pos + 1])
	{
		// matrix = (t_matrix*)malloc(sizeof(t_matrix));
		// ((!matrix) ? (ft_error("matrix creation failed")) : (matrix));
		ft_initmatrix(matrix, dim);
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
				printf("x = %i , y = %i\n", matrix->pos[subunit_nb].x, matrix->pos[subunit_nb].y);
				x_pos++;
				subunit_nb++;
			}
			else if (str[str_pos] == '\n')
			{
				y_pos--;
				x_pos = 0;
			}
			else if (str[str_pos] != '.')
				ft_error("input error");
			while (subunit_nb == 4 && str[str_pos] && \
				!(str[str_pos] == '\n' && str[str_pos + 1] == '\n'))
				str_pos++;
			str_pos++;
		}
		matrix = matrix->next;
	}
	printf("ending\n");
	matrix = matrix->first;
	return (matrix);
}
