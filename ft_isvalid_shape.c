/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_shape.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:40:54 by ilarbi            #+#    #+#             */
/*   Updated: 2017/01/18 16:21:43 by ilarbi           ###   ########.fr       */
/*   Updated: 2017/01/15 22:04:41 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>

static	int		ft_right(char **bloc, int i, int j)
{
	return ((i < 4 && ((j + 1) < 4) && bloc[i][j + 1] == '#') ? 1 : 0);
}

static	int		ft_left(char **bloc, int i, int j)
{
	return ((i < 4 && ((j - 1) >= 0) && bloc[i][j - 1] == '#') ? 1 : 0);
}

static	int		ft_up(char **bloc, int i, int j)
{
	return ((((i - 1) >= 0) && ((j) >= 0) && bloc[i - 1][j] == '#') ? 1 : 0);
}

static	int		ft_down(char **bloc, int i, int j)
{
	return ((((i + 1) < 4) && bloc[i + 1][j] == '#') ? 1 : 0);
}

int				ft_isvalid_shape(char **bloc, int i, int j, int *count)
{
	*count += 1;
	bloc[i][j] = 1;
	if (ft_up(bloc,i,j))
	{
		ft_putstr("up\n");
		ft_isvalid_shape(bloc, (i - 1), j, count);
	}
	if (ft_right(bloc,i,j))
	{
		ft_putstr("right\n");
		ft_isvalid_shape(bloc, i, (j + 1), count);
	}
	if (ft_left(bloc,i,j))
	{
		ft_putstr("left\n");
		ft_isvalid_shape(bloc, i, (j - 1), count);
	}
	if (ft_down(bloc,i,j))
	{
		ft_putstr("down\n");
		ft_isvalid_shape(bloc, (i + 1), j, count);
	}
	printf("count = %d\n", *count);
	return ((*count == 4) ? 1 : 0);
}
/*
int		main(void)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char 	**bloc;
	char	**tmp;

	i = 0;
	j = 0;
	k = 1;
	count = 0;
	
	char *input = "..##\n.##.\n....\n....\n\n..##\n..##\n....\n....\n\n##...\n#...\n.#..\n....\n";
//	bloc = (char**)(malloc(sizeof(char *) * (5)));
	bloc = ft_strsplit(input, '\n');
	tmp = (char **)malloc(sizeof(char *) * 5);
	while (i < 4)
		tmp[i++] = (char *)malloc(sizeof(char) * 5);
	tmp[4] = 0;
	while (k <= 3)
	{
		while (i < (4 * k) && k <= 3)
		{
			printf("i = %d , k = %d , donc je rentre \n", i, k);
			if (bloc[i][j] == '#')
			{
				printf("i = %d, j = %d\n",i,j);
				printf("%d\n",ft_isvalid_shape(bloc, i, j, &count));
				break;
			}
			j++;
			printf("new j = %d = %c\n", j, bloc[i][j]);
			if (j == 4)
			{	
				j = 0;
				i++;
				printf("got next line\n");
			}
		}
		i = 4 * k;
		k++;
		j = 0;
	}
//	printf("%d\n", ft_isvalid_shape(bloc, 8, 1, &count));
	return (0);
}*/
