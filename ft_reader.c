/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <ilarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:01:57 by ilarbi            #+#    #+#             */
/*   Updated: 2017/03/20 19:46:33 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static	int		ft_isvalid(char *input)
{
	t_pieces	t_p;

	PIECES = 0;
	while (*input)
	{
		I = 0;
		DIESE = 0;
		while (*input != '\n' && (*input && *(input + 1) != '\n'))
		{
			J = -1;
			while (*input != '\n' && (*input == '#' || *input == '.'))
				((t_p.j++ && *(input++) == '#') ? (t_p.diese)++ : t_p.diese);
			if (J != 4 || *input != '\n')
				ft_error();
			input++;
			I++;
		}
		if (DIESE != 4 || I != 4)
			ft_error();
		PIECES++;
		if (*input == '\0')
			return (PIECES);
		input++;
	}
	return (0);
}

static int		ft_isvalid_shape(char **bloc, int i, int j, int *count)
{
	*count += 1;
	bloc[i][j] = '1';
	if (((i - 1) >= 0) && ((j) >= 0) && bloc[i - 1][j] == '#')
	{
		ft_isvalid_shape(bloc, (i - 1), j, count);
	}
	if (i < 4 && ((j + 1) < 4) && bloc[i][j + 1] == '#')
	{
		ft_isvalid_shape(bloc, i, (j + 1), count);
	}
	if (i < 4 && ((j - 1) >= 0) && bloc[i][j - 1] == '#')
	{
		ft_isvalid_shape(bloc, i, (j - 1), count);
	}
	if (((i + 1) < 4) && bloc[i + 1][j] == '#')
	{
		ft_isvalid_shape(bloc, (i + 1), j, count);
	}
	return ((*count == 4) ? 1 : 0);
}

static int		ft_scan_bloc(char **tmp)
{
	int			i;
	int			j;
	int			count;
	int			ret;

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
	int			i;
	int			j;
	int			k;
	int			line;
	char		**tmp;

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

int				ft_reader(char *input)
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
