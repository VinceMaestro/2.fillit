/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbestshape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 04:15:14 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/08 20:43:28 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_matrix	*ft_m_increasedim(t_matrix *matrix)
{
	while (matrix)
	{
		matrix->dim += 1;
		if (!matrix->next)
			return (matrix = matrix->first);
		matrix = matrix->next;
	}
	ft_error("FT_M_INCEASEDIM: Fail to increase matrix dim");
	return (NULL);
}

static t_map	*ft_m_append(t_map *map, t_matrix *matrix)
{
	int		cpt_mx;

	cpt_mx = 0;
	ft_printmatrix(matrix);
	while (cpt_mx < 4)
	{
		ft_putstr("x = ");
		ft_putnbr(matrix->pos[cpt_mx].x);
		ft_putstr("; y = ");
		ft_putnbr(matrix->pos[cpt_mx].y);
		ft_putstr(" \n");
		ft_putnbr(map->x[matrix->pos[cpt_mx].x][matrix->pos[cpt_mx].y]);
		ft_putstr(" \n");
		if (map->x[matrix->pos[cpt_mx].x][matrix->pos[cpt_mx].y] == 1)
			return (NULL);
		cpt_mx++;
	}
	while (cpt_mx)
	{
		map->x[matrix->pos[cpt_mx].x][matrix->pos[cpt_mx].y] = 1;
		cpt_mx--;
	}
	ft_putstr(":INFO: Ft_m_append : exiting\n");
	return (map);
}

static t_map	*ft_m_pop(t_map *map, t_matrix *matrix)
{
	int		cpt_mx;

	cpt_mx = 0;
	while (cpt_mx < 4)
	{
		if (!(map->x[matrix->pos[cpt_mx].x][matrix->pos[cpt_mx].y]))
			ft_error("FT_M_POP: pop fail");
		cpt_mx++;
	}
	while (cpt_mx)
	{
		map->x[matrix->pos[cpt_mx].x][matrix->pos[cpt_mx].y] = 0;
		cpt_mx--;
	}
	return (map);
}

static t_matrix	*ft_iter(t_matrix *matrix, t_map *map)
{
	int		pop;

	pop = 0;
	ft_putstr(":INFO: Ft_iter\n");
	while (matrix)
	{
		ft_putstr(":INFO: Ft_iter : matrix\n");
		while (!ft_m_append(map, matrix) || pop == 1)
		{
			ft_putstr(":INFO: Ft_iter: !ft_m_append\n");
			pop = 0;
			if (matrix->pos[0].x == ft_m_xplus(matrix, 1)->pos[0].x)
			{
				ft_putstr(":INFO: Ft_iter: x_max\n");
				if (matrix->pos[0].y == ft_m_yplus(matrix, -1)->pos[0].y)
				{
					matrix = ft_transfmatrix(matrix);
					if (matrix == ft_m_prev(matrix))
						return (NULL);
					matrix = ft_m_prev(matrix);
					map = ft_m_pop(map, matrix);
					pop = 1;
				}
				else
					ft_m_xplus(matrix, -matrix->dim);
			}
			else
				ft_putstr(":INFO: Ft_iter: decale x\n");
		}
		ft_putstr(":INFO: Ft_iter: m_append\n");
		map = ft_m_append(map, matrix);
		ft_putstr(":INFO: Ft_iter: m_append Success\n");
		ft_putstr(":INFO: Ft_iter: matrix->next\n");
		if (!(matrix->next))
			return (matrix = matrix->first);
		matrix = matrix->next;
		ft_putstr(":INFO: Ft_iter: matrix->next Success\n");
	}
	ft_error("FT_ITER: Comes to an unexpected end");
	return (NULL);
}

t_matrix	*ft_getbestshape(t_matrix *matrix)
{
	t_map		*map;
	t_matrix	*tmp;

	map = (t_map*)malloc(sizeof(t_map));
	if (!matrix)
		ft_error("FT_GETBESTSHAPE: Missing matrix");
	if (!map)
		ft_error("FT_GETBESTSHAPE: Malloc Failed");
	map = ft_mapalloc(map, matrix->dim);
	ft_putstr(":INFO: Alloc ok\n");
	while (!(tmp = ft_iter(matrix, map)))
	{
		matrix = ft_m_increasedim(matrix);
		matrix = ft_transfallmatrix(matrix);
		map = ft_mapalloc(map, matrix->dim);
	}
	matrix = tmp;
	return (matrix);
}
