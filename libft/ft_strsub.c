/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:31:20 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:59:23 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	new = NULL;
	if (s)
	{
		new = ft_memalloc(len + 1);
		if (new)
			ft_memcpy(new, &s[start], len);
		else
			return (new);
		new[len] = '\0';
	}
	return (new);
}
