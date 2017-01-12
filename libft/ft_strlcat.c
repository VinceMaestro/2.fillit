/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:39:31 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 05:42:40 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	char	*pos;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	pos = ft_memchr(dst, '\0', size);
	if (!pos)
		return (src_len + size);
	if (size > dst_len + 1)
	{
		while (*src && (size_t)(pos - dst) < size - 1)
			ft_memcpy(pos++, src++, 1);
		*pos = '\0';
	}
	return (dst_len + src_len);
}
