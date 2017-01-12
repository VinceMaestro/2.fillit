/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:09:02 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/03 17:03:07 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	conv_c;
	unsigned char	*conv_dst;
	unsigned char	*conv_src;

	i = 0;
	conv_src = (unsigned char*)src;
	conv_dst = (unsigned char*)dst;
	conv_c = (unsigned char)c;
	while (i < n)
	{
		conv_dst[i] = conv_src[i];
		if (conv_dst[i] == conv_c)
		{
			dst = (void*)conv_dst;
			return (&dst[i + 1]);
		}
		i += 1;
	}
	return (NULL);
}
