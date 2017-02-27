/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <ilarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:34:24 by ilarbi            #+#    #+#             */
/*   Updated: 2017/02/27 21:09:20 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static	void	ft_elt(char **map, t_matrix *elt)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map[(elt->pos[i].y) * (-1)][elt->pos[i].x] = elt->name;
		i++;
	}
}

static void		ft_print(char **map, int dim)
{
	int		x;
	int		y;

	y = 0;
	while (y < dim)
	{
		x = 0;
		while (x < dim)
		{
			if (map[y][x])
				ft_putchar(map[y][x]);
			else
				ft_putchar('.');
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}

char			**ft_map(t_matrix *first)
{
	int			i;
	t_matrix	*current;
	char		**map;

	i = 0;
	current = first;
	if (!(map = (char **)malloc(sizeof(char *) * (first->dim + 1))))
		return (NULL);
	map[first->dim] = 0;
	while (i < first->dim)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (first->dim + 1))))
			return (NULL);
		ft_bzero(map[i++], first->dim + 1);
	}
	while (current)
	{
		ft_elt(map, current);
		current = current->next;
	}
	ft_print(map, first->dim);
	return (map);
}
