/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:31:04 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:58:02 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char const *s1)
{
	char	*s1_copy;
	int		s1_len;
	int		i;

	s1_len = 0;
	i = 0;
	while (s1[s1_len] != '\0')
		s1_len += 1;
	s1_copy = (char*)malloc(sizeof(*s1_copy) * (s1_len + 1));
	if (s1_copy != NULL)
	{
		while (i < s1_len)
		{
			s1_copy[i] = s1[i];
			i += 1;
		}
		s1_copy[i] = '\0';
	}
	return (s1_copy);
}
