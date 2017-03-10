/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <ilarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:01:57 by ilarbi            #+#    #+#             */
/*   Updated: 2017/03/10 18:51:45 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

static	int		ft_isvalid_char(char c)
{
	return ((c == '#' || c == '.') ? 1 : 0);
}

static	int		ft_isvalid(char *input)
{
	int		i;
	int		j;
	int		diese;
	int		pieces;

	pieces = 0;
	while (*input)
	{
		i = 0;
		diese = 0;
		while (*input != '\n' && (*input && *(input + 1) != '\n'))
		{
		j = 0;
			while (*input != '\n' && ft_isvalid_char(*input))
			{
				((*input == '#') ? diese++ : diese);
				input++;
				j++;
			}
			if (j != 4 || *input != '\n')
				ft_error();
			input++;//passer du \n a la ligne vide
			i++;
		}
		if (diese != 4 || i != 4)
			ft_error();
		pieces++;
		if (*input == '\0')
		   return (pieces);
		input++;//1er char bloc suiv.
	}
	return (0);
}

static int		ft_scan_bloc(char **tmp)
{
	int	i;
	int	j;
	int	count;
	int ret;

	i = 0;
	j = 0;
	count = 0;
	ret = 0;
	while (i < 4)
	{
		if (tmp[i][j] == '#')
			return ((ret = ft_isvalid_shape(tmp, i, j, &count)));
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
	}
	return (0);
}

static	int		ft_scan_pieces(char **bloc, int pieces)
{
	int		i;
	int		j;
	int		k;
	int		line;
	char	**tmp;

	i = 0;
	k = 1;
	tmp = (char **)malloc(sizeof(char *) * 5);
	tmp[4] = 0;
	while (i < 4 * k && k <= pieces)
	{
		j = 0;
		line = 0;
		while (line < 4)
		{
			tmp[line] = (char *)malloc(sizeof(char *) * 5);
			tmp[line++] = bloc[i++];
		}
		if (!ft_scan_bloc(tmp))
			ft_error();
		i = 4 * k;
		k++;
	}
	return (1);
}

int			ft_reader(char *input)
{
	int		pieces;
	char	**bloc;

	if (input)
	{
		pieces = ft_isvalid(input);
		if (pieces == 0)
			ft_error();
		bloc = ft_strsplit(input, '\n');
		if (!ft_scan_pieces(bloc, pieces))
			ft_error();
		return (pieces);
	}
	return (0);
}
