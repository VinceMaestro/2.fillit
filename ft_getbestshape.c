/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbestshape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 04:15:14 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/22 17:20:46 by vpetit           ###   ########.fr       */
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
		{
			ft_printmatrix(matrix);
			ft_putstr("Should be : ");
			ft_putnbr(matrix->pos[cpt_mx].x);
			ft_error("matrix X trop petite");
		}
		if (matrix->pos[cpt_mx].y <= -matrix->dim)
		{
			ft_putnbr(matrix->pos[cpt_mx].y);
			ft_error("matrix Y trop petite");
		}
		if ((*map)->axis[matrix->pos[cpt_mx].x][-matrix->pos[cpt_mx].y] == 1)
		{
			return (NULL);
		}
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
			ft_error("FT_M_POP: pop fail");
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

static t_matrix	*ft_iter(t_matrix *mtrx, t_map *map)
{
	int			pop;
	t_matrix	tmp;

	pop = 0;
	while (mtrx)
	{
		while (!ft_m_append(&map, mtrx) || pop == 1)
		{
			pop = 0;
			if (mtrx->pos[0].x == (tmp = *ft_m_xplus(mtrx, 1)).pos[0].x)
			{
				if (mtrx->pos[0].y == (tmp = *ft_m_yplus(mtrx, -1)).pos[0].y)
				{
					mtrx = ft_transfmatrix(mtrx);
					if (mtrx == ft_m_prev(mtrx))
						return (NULL);
					mtrx = ft_m_prev(mtrx);
					map = ft_m_pop(&map, mtrx);
					pop = 1;
				}
				else
					ft_m_xplus(mtrx, -mtrx->dim);
			}
		}
		if (!mtrx->next)
			return (mtrx = mtrx->first);
		mtrx = mtrx->next;
	}
	ft_error("FT_ITER: Comes to an unexpected end");
	return (NULL);
}

t_matrix		*ft_getbestshape(t_matrix *matrix)
{
	t_map		map;
	t_matrix	*tmp;

	if (!matrix)
		ft_error("FT_GETBESTSHAPE: Missing matrix");
	ft_mapalloc(&map, matrix->dim);
	while (!(tmp = ft_iter(matrix, &map)))
	{
		matrix = ft_m_increasedim(matrix);
		matrix = ft_transfallmatrix(matrix);
		ft_mapalloc(&map, matrix->dim);
	}
	matrix = tmp;
	ft_printmap(map, matrix->dim);
	return (matrix);
}
