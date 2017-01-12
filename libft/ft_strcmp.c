/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:04:18 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/03 17:04:14 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				count;
	unsigned char	*conv_s1;
	unsigned char	*conv_s2;

	count = 0;
	conv_s1 = (unsigned char*)s1;
	conv_s2 = (unsigned char*)s2;
	while (conv_s1[count] && conv_s1[count] == conv_s2[count])
		count++;
	return (conv_s1[count] - conv_s2[count]);
}
