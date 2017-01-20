/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimpiece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:44:20 by ilarbi            #+#    #+#             */
/*   Updated: 2017/01/20 20:54:18 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft/libft.h"

char	*ft_strtrimpiece(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*fresh;

	start = 0;
	fresh = NULL;
	if (s)
	{
		end = ft_strlen(s) - 1;
		while (s[start] == '.' || s[start] == '\n')
			start++;
		while (s[end] == '.' || s[end] == '\n')
			end--;
		((start > end) ? (len = 1) :
		(len = end - start + 2));
		fresh = (char *)malloc(sizeof(char) * (len));
		if (fresh != NULL)
		{
			ft_memcpy(fresh, &s[start], len - 1);
			fresh[len - 1] = '\0';
		}
	}
	return (fresh);
}
