/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:34:24 by ilarbi            #+#    #+#             */
/*   Updated: 2017/01/31 22:17:19 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

//maps the final square
static	void	ft_elt(char **map, t_matrix *elt)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map[(elt->pos[i].y) * (-1)][elt->pos[i].x] = elt->name;
		printf("map[%d][%d]  %c\n", elt->pos[i].y, elt->pos[i].x , map[(elt->pos[i].y) * (-1)][elt->pos[i].x]);
		i++;
	}
}

char			**ft_map(t_matrix *first, char **map, void (*f)(char **map, t_matrix *elt))
{
	//ft_lstiter(ft_elt, &ft_elt);
	t_matrix	*current;

	current = first;
	while (current && f)
	{
		f(map, current);
		current = current->next;
	}
	return (map);
}

int		main(void)
{
	int			dim;
	int			i;
	int			j;
	char		**map;
	t_matrix	*first;
	t_matrix	*current;

	i = 0;
	j = 0;
	dim = 5;	
	map = (char **)malloc(sizeof(char *)  * dim);
	while (i < dim)
		map[i++] = (char*)malloc(sizeof(char) * dim);
	first = (t_matrix *)malloc(sizeof(t_matrix));
	current = (t_matrix *)malloc(sizeof(t_matrix));
	if (!map || !first || !current)
	{
		printf("malloc failed\n");
		exit(1);
	}	
	printf("ok!\n");
	first->name = 'A';
	first->dim = dim;
	first->pos = (t_pos*)malloc(sizeof(t_pos) * 4);
	first->pos[0].x = 1;
	first->pos[0].y = 0;
	first->pos[1].x = 1;
	first->pos[1].y = -1;
	first->pos[2].x = 2;
	first->pos[2].y = -1;
	first->pos[3].x = 1;
	first->pos[3].y = -2;
	first->first = first;
	first->next = current;
	current->name = 'B';
	current->dim = dim;
	current->pos = (t_pos*)malloc(sizeof(t_pos) * 4);
	current->pos[0].x = 0;
	current->pos[0].y = 0;
	current->pos[1].x = 0;
	current->pos[1].y = -1;
	current->pos[2].x = 0;
	current->pos[2].y = -2;
	current->pos[3].x = 0;
	current->pos[3].y = -3;
	current->first = first;
	current->next = NULL;
	i = 0;
	//initialisation a 0
	while (i < dim)
	{
	//	printf("ligne\n");
		while (j < dim)
		{
	//		printf("colonne\n");
			map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	//affichage
	i = 0;
	j = 0;
	while (i < dim)
	{
		while (j < dim)
		{
			printf("%c ", map[i][j]);
		   j++;	
		}
		printf("\n");
		j = 0;
		i++;
	}
	//modif
	ft_map(first, map, &ft_elt); 
	//affichage
	i = 0;
	j = 0;
	while (i < dim)
	{
		while (j < dim)
		{
			printf("%c ", map[i][j]);
		   j++;	
		}
		printf("\n");
		j = 0;
		i++;
	}
}
