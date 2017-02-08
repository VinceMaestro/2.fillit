/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:30:33 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/08 20:50:21 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_map	*ft_mapinit(t_map *map, int dim)
{
	int		x_pos;
	int		y_pos;

	x_pos = 0;
	while (x_pos < dim)
	{
		y_pos = 0;
		while (y_pos < dim)
		{
			map->x[x_pos][y_pos] = 0;
			ft_putstr(":INFO: FT_MAPINIT: ");
			ft_putnbr(map->x[x_pos][y_pos]);
			ft_putstr(" \n");
			y_pos++;
		}
		x_pos++;
	}
	return (map);
}

t_map			*ft_mapalloc(t_map *map, int dim)
{
	int		cpt;

	cpt = 0;
	map->x = (int**)malloc(sizeof(int*) * dim);
	if (!map->x)
		ft_error("FT_GETBESTSHAPE: Malloc failed");
	while (cpt < dim)
	{
		map->x[cpt] = (int*)malloc(sizeof(int) * dim);
		if (!map->x[cpt])
			ft_error("FT_GETBESTSHAPE: Malloc failed");
		cpt++;
	}
	map = ft_mapinit(map, dim);
	return (map);
}
