/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:58:09 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:59:46 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*fresh;

	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (end == 0 || start == end + 1)
	{
		fresh = (char *)malloc(1);
		*fresh = '\0';
		return (fresh);
	}
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	fresh = (char *)malloc(sizeof(char) * (end - start + 2));
	if (fresh != NULL)
	{
		ft_strncpy(fresh, &s[start], end - start + 1);
		fresh[end - start + 1] = '\0';
	}
	return (fresh);
}
