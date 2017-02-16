/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbestshape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 04:15:14 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/16 06:42:24 by vpetit           ###   ########.fr       */
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

static t_matrix	*ft_iter(t_matrix *matrix, t_map *map)
{
	int			pop;
	t_matrix	tmp;

	pop = 0;
	while (matrix)
	{
		while (!ft_m_append(&map, matrix) || pop == 1)
		{
			pop = 0;
			if (matrix->pos[0].x == (tmp = *ft_m_xplus(matrix, 1)).pos[0].x)
			{
				if (matrix->pos[0].y == (tmp = *ft_m_yplus(matrix, -1)).pos[0].y)
				{
					ft_putstr(":INFO: FT_GETBESTSHAPE: Ft_iter: Depile\n");
					matrix = ft_transfmatrix(matrix);
					if (matrix == ft_m_prev(matrix))
						return (NULL);
					matrix = ft_m_prev(matrix);
					map = ft_m_pop(&map, matrix);
					pop = 1;
				}
				else
					ft_m_xplus(matrix, -matrix->dim);
			}
		}
		if (!matrix->next)
			return (matrix = matrix->first);
		matrix = matrix->next;
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
		ft_putstr(":INFO: Finished one ft_iter\n");
		ft_print_allmatrix(matrix);
		matrix = ft_m_increasedim(matrix);
		ft_print_allmatrix(matrix);
		matrix = ft_transfallmatrix(matrix);
		ft_print_allmatrix(matrix);
		ft_mapalloc(&map, matrix->dim);
	}
	matrix = tmp;
	// ft_printmap(map, matrix->dim);
	return (matrix);
}
