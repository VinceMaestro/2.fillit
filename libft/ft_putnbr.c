/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:00:23 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 01:05:51 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_putnbr_neg(long int nbr)
{
	char	buff;

	(nbr % 10 != nbr) ? (ft_putnbr_neg(nbr / 10)) : (write(1, "-", 1));
	buff = '0' + nbr % 10;
	write(1, &buff, 1);
	return (0);
}

int			ft_putnbr(int nbr)
{
	long int	buff;

	buff = '0';
	if (nbr < 0)
		return (ft_putnbr_neg(-(long int)nbr));
	(nbr % 10 != nbr) ? (ft_putnbr(nbr / 10)) : buff;
	buff = '0' + nbr % 10;
	write(1, &buff, 1);
	return (0);
}
