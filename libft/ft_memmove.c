/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:47:42 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/03 17:03:21 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t	end;
	size_t	start;
	char	*conv_src;
	char	*conv_dst;

	conv_src = (char*)src;
	conv_dst = (char*)dst;
	start = 0;
	end = len - 1;
	if (end <= 0)
		return (dst);
	if (src >= dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (end + 1 != 0)
		{
			conv_dst[end] = conv_src[end];
			end--;
		}
		dst = (void*)conv_dst;
	}
	return (dst);
}
