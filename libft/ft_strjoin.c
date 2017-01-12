/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:31:30 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:58:23 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*new;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		new = (char*)malloc(sizeof(*new) * (len_s1 + len_s2 + 1));
		if (new && s1 && s2)
		{
			ft_strcpy(new, s1);
			ft_strcpy(&(new[len_s1]), s2);
			new[len_s1 + len_s2] = '\0';
		}
		return (new);
	}
	return (NULL);
}
