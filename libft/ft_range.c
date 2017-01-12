/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:17:59 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:57:42 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*value_range;
	int		cpt;

	cpt = 0;
	if (min >= max)
		return (0);
	value_range = (int*)malloc(sizeof(*value_range) * (max - min + 1));
	while (cpt < max - min)
	{
		value_range[cpt] = min + cpt;
		cpt += 1;
	}
	value_range[cpt] = '\0';
	return (value_range);
}
