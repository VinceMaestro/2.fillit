/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbestshape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 04:15:14 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/16 17:52:06 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_map	*ft_m_append(t_map **map, t_matrix *matrix)
{
	int		cpt_mx;

	cpt_mx = 0;
	while (cpt_mx < 4)
	{
		if (matrix->pos[cpt_mx].x >= matrix->dim)
			ft_error();
		if (matrix->pos[cpt_mx].y <= -matrix->dim)
			ft_error();
		if ((*map)->axis[matrix->pos[cpt_mx].x][-matrix->pos[cpt_mx].y] == 1)
			return (NULL);
		cpt_mx++;
	}
	cpt_mx--;
	while (cpt_mx >= 0)
	{
		(*map)->axis[matrix->pos[cpt_mx].x][-matrix->pos[cpt_mx].y] = 1;
		cpt_mx--;
	}
	return (*map);
}

static t_map	*ft_m_pop(t_map **map, t_matrix *matrix)
{
	int		cpt_mx;

	cpt_mx = 0;
	while (cpt_mx < 4)
	{
		if (!(*map)->axis[matrix->pos[cpt_mx].x][-matrix->pos[cpt_mx].y])
			ft_error();
		cpt_mx++;
	}
	cpt_mx = 0;
	while (cpt_mx < 4)
	{
		(*map)->axis[matrix->pos[cpt_mx].x][-matrix->pos[cpt_mx].y] = 0;
		cpt_mx++;
	}
	return (*map);
}

static t_matrix	*ft_test_iter(t_matrix *mtrx, t_map **map, int *pop)
{
	t_matrix	tmp;

	if (mtrx->pos[0].x == (tmp = *ft_m_op("X ", mtrx, 1)).pos[0].x)
	{
		if (mtrx->pos[0].y == (tmp = *ft_m_op("Y ", mtrx, -1)).pos[0].y)
		{
			mtrx = ft_transform("1", mtrx, 0);
			if (mtrx == ft_m_op("prev", mtrx, 0) || \
				!(mtrx = ft_m_op("prev", mtrx, 0)))
				return (NULL);
			*map = ft_m_pop(map, mtrx);
			*pop = 1;
		}
		else
			ft_m_op("X ", mtrx, -mtrx->dim);
	}
	return (mtrx);
}

static t_matrix	*ft_iter(t_matrix *mtrx, t_map *map)
{
	int			pop;
	t_matrix	*tmp;

	pop = 0;
	while (mtrx)
	{
		while (pop == 1 || !ft_m_append(&map, mtrx))
		{
			pop = 0;
			if (!(tmp = ft_test_iter(mtrx, &map, &pop)))
				return (NULL);
			mtrx = tmp;
		}
		if (!mtrx->next || !(mtrx = mtrx->next))
			return (mtrx = mtrx->first);
	}
	ft_error();
	return (NULL);
}

t_matrix		*ft_getbestshape(t_matrix *matrix)
{
	t_map		map;
	t_matrix	*tmp;

	if (!matrix)
		ft_error();
	ft_mapalloc(&map, matrix->dim);
	while (!(tmp = ft_iter(matrix, &map)))
	{
		matrix = ft_m_op("incrdim", matrix, 0);
		matrix = ft_transform("1", matrix, 0);
		ft_mapalloc(&map, matrix->dim);
	}
	matrix = tmp;
	return (matrix);
}
