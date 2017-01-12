/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:59:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/12 16:23:24 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_initmatrix(t_matrix *matrix, t_matrix *new int name)
{
	new->name = matrix->name + 1;
	new->dim = matrix->dim;
	new->pos = (t_pos*)malloc(sizeof(t_pos) * 4);
	(!(new->pos) ? (ft_error()) : (new));
	new->first = matrix->first;
	new->next = NULL;
	matrix->next = new;
}

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

static t_matrix	*ft_newmatrix(t_matrix* matrix, char *str)
{
	t_matrix	*new;

	ft_getmatrix(matrix, LAST);
	new = (t_matrix*)malloc(sizeof(t_matrix));
	(!(new) ? (ft_error()) : (new));
	ft_initmatrix(matrix, new);
	ft_strtomatrix(new->pos, str);
	matrix = matrix->first;
	return (new);
}

static void	ft_strtopos(t_pos *pos, char *str)
{
	int		piece_nb;
	int		x_pos;
	int		y_pos;
	int		subunit_nb;
	int		str_pos;

	piece_nb = 0;
	str_pos = 0;
	while (str[str_pos])
	{
		subunit_nb = 0;
		x_pos = 0;
		y_pos = 0;
		while (subunit_nb < 4)
		{
			if (str[str_pos] == '#')
			{
				pos[piece_nb][subunit_nb]->x = x_pos;
				pos[piece_nb][subunit_nb]->y = y_pos;
				pos[piece_nb][subunit_nb]->z = 1;
				x_pos++;
				subunit_nb++;
			}
			else if (str[str_pos] == '\n')
			{
				y_pos--;
				x_pos = 0;
			}
			else if (str[str_pos] != '#')
				ft_error();
			str_pos++;
		}
	}
}
