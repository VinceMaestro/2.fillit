/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_shape.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <ilarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:40:54 by ilarbi            #+#    #+#             */
/*   Updated: 2017/02/27 16:52:02 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
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
		ft_isvalid_shape(bloc, (i - 1), j, count);
	}
	if (ft_right(bloc, i, j))
	{
		ft_isvalid_shape(bloc, i, (j + 1), count);
	}
	if (ft_left(bloc, i, j))
	{
		ft_isvalid_shape(bloc, i, (j - 1), count);
	}
	if (ft_down(bloc, i, j))
	{
		ft_isvalid_shape(bloc, (i + 1), j, count);
	}
	return ((*count == 4) ? 1 : 0);
}
