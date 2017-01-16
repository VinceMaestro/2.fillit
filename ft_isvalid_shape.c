/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_shape.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:40:54 by ilarbi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/01/15 22:21:19 by ilarbi           ###   ########.fr       */
=======
/*   Updated: 2017/01/15 22:04:41 by ilarbi           ###   ########.fr       */
>>>>>>> 1b0cc8f405fffc7e4bee592329417012c4d384b9
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>

int		ft_right(char **bloc, int i, int j)
{
	return ((i < 4 && ((j + 1) < 4) && bloc[i][j + 1] == '#') ? 1 : 0);
}

int		ft_left(char **bloc, int i, int j)
{
	return ((i < 4 && ((j - 1) >= 0) && bloc[i][j - 1] == '#') ? 1 : 0);
}

int		ft_up(char **bloc, int i, int j)
{
	return ((((i - 1) >= 0) && ((j) >= 0) && bloc[i - 1][j] == '#') ? 1 : 0);
}

int		ft_down(char **bloc, int i, int j)
{
	return ((((i + 1) < 4) && bloc[i + 1][j] == '#') ? 1 : 0);
}

int		ft_isvalid_shape(char **bloc, int i, int j, int *count)
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
	return ((*count == 4) ? 1 : 0);
}

int		main(void)
{
	int		i;
	int		j;
	int		count;
	char 	**bloc;

	i = 0;
	j = 0;
	count = 0;
	
	char *input = "..##\n\n.##.\n\n....\n\n....\n";
	bloc = (char**)(malloc(sizeof(char *) * (5)));
	while (i < 4)
	{
		bloc[i++] = (char *)malloc(sizeof(char) * 5);
	}
	bloc = ft_strsplit(input, '\n');
	//bloc[4] = 0;
	i = 0;
	while (i < 4)
	{
		if (bloc[i][j] == '#')
			break;
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
	}
	printf("%d\n", ft_isvalid_shape(bloc, 1, 2, &count));
	return (0);
}
