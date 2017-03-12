/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfallmatrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 13:10:26 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/11 16:25:26 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_matrix	*ft_checkshape(t_matrix *matrix)
{
	int		dim;
	int		subunit;

	dim = matrix->dim;
	subunit = 0;
	while (subunit < 4)
	{
		if (matrix->pos[subunit].x >= dim || -matrix->pos[subunit].y >= dim)
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

static t_matrix	*ft_transfmatrix(t_matrix *matrix)
{
	matrix = ft_m_xplus(matrix, -matrix->dim);
	matrix = ft_m_yplus(matrix, matrix->dim);
	return (matrix);
}

static t_matrix	*ft_transfallmatrix(t_matrix *matrix, int piece_nb)
{
	if (matrix)
	{
		matrix = ft_transfmatrix(matrix);
		while (matrix->next)
		{
			matrix = matrix->next;
			matrix = ft_transfmatrix(matrix);
		}
		matrix = matrix->first;
	}
	if (piece_nb < 3)
		matrix = ft_checkshape(matrix);
	return (matrix);
}

t_matrix		*ft_transform(char *str, t_matrix *matrix, int piece_nb)
{
	if (!(ft_strcmp(str, "ALL")))
		matrix = ft_transfallmatrix(matrix, piece_nb);
	else
		matrix = ft_transfmatrix(matrix);
	return (matrix);
}
