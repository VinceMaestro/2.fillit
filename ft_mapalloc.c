/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:30:33 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/15 22:18:18 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_map	*ft_mapinit(t_map *map, int dim)
{
	int		x_pos;
	int		y_pos;

	y_pos = 0;
	while (y_pos < dim)
	{
		x_pos = 0;
		while (x_pos < dim)
		{
			map->axis[x_pos][y_pos] = 0;
			x_pos++;
		}
		y_pos++;
	}
	return (map);
}

t_map			*ft_mapalloc(t_map *map, int dim)
{
	int		cpt;

	cpt = 0;
	map->axis = (int**)malloc(sizeof(int*) * dim);
	if (!map->axis)
		ft_error("FT_GETBESTSHAPE: Malloc failed");
	while (cpt < dim)
	{
		map->axis[cpt] = (int*)malloc(sizeof(int) * dim);
		if (!map->axis[cpt])
			ft_error("FT_GETBESTSHAPE: Malloc failed");
		cpt++;
	}
	map = ft_mapinit(map, dim);
	return (map);
}
