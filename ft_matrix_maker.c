/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:59:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/12 17:45:34 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_initmatrix(t_matrix *matrix, int dim)
{
	t_matrix	*new;

	new = (t_matrix*)malloc(sizeof(t_matrix));
	(!(new) ? (ft_error("FAILED : malloc new")) : (new));
	new->pos = (t_pos*)malloc(sizeof(t_pos) * 4);
	(!(new->pos) ? (ft_error("FAILED : malloc pos")) : (new));
	ft_getmatrix(matrix, LAST);
	new->name = 'A' + (matrix - matrix->first);
	new->dim = dim;
	((matrix->first) ? (new->first = matrix->first) :\
		(new->first = new));
	new->next = NULL;
	((matrix != new) ? (matrix->next = new) : (matrix));

	}
	else
	{
		new->name = matrix->name + 1;
		new->dim = matrix->dim;
		new->first = matrix->first;
		new->next = NULL;
		matrix->next = new;
	}
	new->pos->x = 0;
	new->pos->y = 0;
	new->pos->z = 1;
	matrix = matrix->first;
}

// ft_getmatrix(matrix, LAST);
static int	ft_getmatrix(t_matrix* matrix, char name) // IF name = LAST (donc 1) se place sur le dernier maillon
{
	if (matrix)
	{
		while(matrix->next && matrix->name != name)
			matrix = matrix->next;
		if (matrix->name == name)
			return (1);
	}
	return (0);
}

static void	ft_savepos(t_pos *pos, x_pos, y_pos)
{
	pos->x = x_pos;
	pos->y = y_pos;
}

static void	ft_strtopos(t_matrix *matrix, char *str)
{
	int		x_pos;
	int		y_pos;
	int		subunit_nb;
	int		str_pos;

	str_pos = 0;
	while (str[str_pos + 1])
	{
		subunit_nb = 0;
		x_pos = 0;
		y_pos = 0;
		while (subunit_nb < 3 && str[str_pos])
		{
			if (str[str_pos] == '#')
			{
				ft_savepos(&(matrix->pos[subunit_nb]), x_pos, y_pos)
				x_pos++;
				subunit_nb++;
			}
			else if (str[str_pos] == '\n')
			{
				y_pos--;
				x_pos = 0;
			}
			else if (str[str_pos] != '.')
				ft_error();
			str_pos++;
		}
		matrix = matrix->next;
	}
	matrix = matrix->first;
}

t_matrix		*ft_matrix_maker(char *str, int dim)
{
	ft_initmatrix(new, new);
	ft_strtopos(new->pos, str);
	matrix = matrix->first;
	return (new);
}
