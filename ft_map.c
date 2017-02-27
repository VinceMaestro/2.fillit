/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:34:24 by ilarbi            #+#    #+#             */
/*   Updated: 2017/02/27 19:55:55 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

static	void	ft_elt(char **map, t_matrix *elt)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map[(elt->pos[i].y) * (-1)][elt->pos[i].x] = elt->name;
		printf("map[%d][%d]  %c\n", elt->pos[i].y, elt->pos[i].x,
				map[(elt->pos[i].y) * (-1)][elt->pos[i].x]);
		i++;
	}
}

char			**ft_map(t_matrix *first, void (*f)(char **map, t_matrix *elt))
{
	int			i;
	t_matrix	*current;
	char		**map;

	i = 0;
	current = first;
	if (!(map = (char **)malloc(sizeof(char *) * (first->dim + 1))))
		return (-1);
	map[first->dim] = 0;
	while (i < (first->dim) + 1)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (first->dim + 1))))
			return (-1);
		map[i++][first->dim] = '\0';
	}
	while (current && f)
	{
		f(map, current);
		current = current->next;
	}
	return (map);
}
