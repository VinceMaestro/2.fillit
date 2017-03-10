/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbestshape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 04:15:14 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/10 18:20:09 by ilarbi           ###   ########.fr       */
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

static t_matrix	*ft_iter(t_matrix *mtrx, t_map *map)
{
	int			pop;
	t_matrix	tmp;

	pop = 0;
//	ft_putstr("Matrix dim : ");
//	ft_putnbr(mtrx->dim);
//	ft_putchar('\n');
	while (mtrx)
	{
//		ft_putstr("New Matrix : ");
//		ft_putchar(mtrx->name);
//		ft_putchar('\n');
		while (pop == 1 || !ft_m_append(&map, mtrx))
		{
			pop = 0;
			if (mtrx->pos[0].x == (tmp = *ft_m_xplus(mtrx, 1)).pos[0].x)
			{
				if (mtrx->pos[0].y == (tmp = *ft_m_yplus(mtrx, -1)).pos[0].y)
				{
//					ft_putstr("=====================================\n");
					mtrx = ft_transfmatrix(mtrx);
//					ft_putstr("Replace matrice en haut a gauche pour prochaine utilisation : ");
//					ft_putchar(mtrx->name);
//					ft_putchar('\n');
					if (mtrx == ft_m_prev(mtrx))
					{
//						ft_putstr("La matrice precedente est la meme que l'acctuelle donc, increase matrix dim\n");
						return (NULL);
					}
//					ft_putstr("Matrix pop\n");
					mtrx = ft_m_prev(mtrx);
//					ft_putstr("Matrix is now : ");
//					ft_putchar(mtrx->name);
//					ft_putchar('\n');
					map = ft_m_pop(&map, mtrx);
					pop = 1;
//					ft_putstr("Pop = 1 donc la matrice acctuelle avait deja ete placee mais on doit la deplacer car la matrice suivante ne loge pas\n");
				}
				else
				{
//					ft_putstr("y moins\n");
//					ft_putstr("reset x\n");
					ft_m_xplus(mtrx, -mtrx->dim);
				}
			}
//			else
//				ft_putstr("x plus\n");
		}
//		ft_putstr("Matrix callée\n");
		if (!mtrx->next)
			return (mtrx = mtrx->first);
		mtrx = mtrx->next;
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
		matrix = ft_m_increasedim(matrix);
		matrix = ft_transfmatrix(matrix);
		ft_mapalloc(&map, matrix->dim);
	}
	matrix = tmp;
	return (matrix);
}
