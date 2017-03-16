/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_shape.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <ilarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:40:54 by ilarbi            #+#    #+#             */
/*   Updated: 2017/03/16 17:36:33 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int				ft_isvalid_shape(char **bloc, int i, int j, int *count)
{
	*count += 1;
	bloc[i][j] = '1';
	if ((((i - 1) >= 0) && ((j) >= 0) && bloc[i - 1][j] == '#'))
	{
		ft_isvalid_shape(bloc, (i - 1), j, count);
	}
	if ((i < 4 && ((j + 1) < 4) && bloc[i][j + 1] == '#'))
	{
		ft_isvalid_shape(bloc, i, (j + 1), count);
	}
	if ((i < 4 && ((j - 1) >= 0) && bloc[i][j - 1] == '#'))
	{
		ft_isvalid_shape(bloc, i, (j - 1), count);
	}
	if ((((i + 1) < 4) && bloc[i + 1][j] == '#'))
	{
		ft_isvalid_shape(bloc, (i + 1), j, count);
	}
	return ((*count == 4) ? 1 : 0);
}
