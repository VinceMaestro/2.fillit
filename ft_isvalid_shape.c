/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_shape.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <ilarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:40:54 by ilarbi            #+#    #+#             */
/*   Updated: 2017/01/31 20:23:27 by vpetit           ###   ########.fr       */
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
	bloc[i][j] = '1';
	if (ft_up(bloc, i, j))
	{
		// ft_putstr("up\n");
		ft_isvalid_shape(bloc, (i - 1), j, count);
	}
	if (ft_right(bloc, i, j))
	{
		// ft_putstr("right\n");
		ft_isvalid_shape(bloc, i, (j + 1), count);
	}
	if (ft_left(bloc, i, j))
	{
		// ft_putstr("left\n");
		ft_isvalid_shape(bloc, i, (j - 1), count);
	}
	if (ft_down(bloc, i, j))
	{
		// ft_putstr("down\n");
		ft_isvalid_shape(bloc, (i + 1), j, count);
	}
	// printf("count = %d\n", *count);
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
	//char	**tmp;

	i = 0;
	j = 0;
	k = 1;
	count = 0;

	char *input = "..##\n.##.\n....\n....\n";
	//\n..##\n..##\n....\n....\n\n##...\n#...\n.#..\n....\n";
	bloc = ft_strsplit(input, '\n');
	tmp = (char **)malloc(sizeof(char *) * 5);
	while (i < 4)
		tmp[i++] = (char *)malloc(sizeof(char) * 5);
	tmp[4] = 0;enlever tte ref a tmp*/
/*		while (i < 4)
		{
			if (bloc[i][j] == '#')
			{
				printf("%d\n",ft_isvalid_shape(bloc, i, j, &count));
				break;
			}
			j++;
			if (j == 4)
			{
				j = 0;
				i++;
			}
		}
		i = 0;
		j = 0;
		while (i < 4)
		{
			while (j < 4)
			{
				if (bloc[i][j] == '.')
					bloc[i][j] = '0';
				printf(" %c ", bloc[i][j]);
				j++;
			}
			printf("\n");
			j = 0;
			i++;
		}
		//	printf("%d\n", ft_isvalid_shape(bloc, 8, 1, &count));
	return (0);
}*/
