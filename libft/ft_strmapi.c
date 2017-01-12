/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:30:45 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:58:47 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buff;

	i = 0;
	if (s && f)
	{
		buff = (char*)malloc(sizeof(*buff) * (ft_strlen(s) + 1));
		if (buff)
		{
			while (s[i])
			{
				buff[i] = f(i, s[i]);
				i++;
			}
			buff[i] = '\0';
		}
	}
	else
		return (NULL);
	return (buff);
}
