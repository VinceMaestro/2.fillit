/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:30:32 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:58:38 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*buff;

	i = 0;
	if (s && f)
	{
		buff = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (buff)
		{
			while (s[i])
			{
				buff[i] = f(s[i]);
				i++;
			}
			buff[i] = '\0';
		}
	}
	else
		return (NULL);
	return (buff);
}
