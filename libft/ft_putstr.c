/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:55:31 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 01:06:15 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr(void *str)
{
	char	*buff;
	int		i;

	if (str)
	{
		buff = str;
		i = 0;
		while (buff[i])
		{
			write(1, &(buff[i]), 1);
			i += 1;
		}
	}
}
