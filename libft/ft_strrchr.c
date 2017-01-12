/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:24:58 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:40:50 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	if (*s && *s == c)
		return (ft_strrchr(s + 1, c) ? ft_strrchr(s + 1, c) : (char*)s);
	else if (*s)
		return (ft_strrchr(s + 1, c));
	else if (*s == c)
		return ((char*)s);
	else
		return (NULL);
}
