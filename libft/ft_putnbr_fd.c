/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:27:34 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 01:05:20 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_putnbr_neg_fd(long int nbr, int fd)
{
	char	buff;

	(nbr % 10 != nbr) ? (ft_putnbr_neg_fd(nbr / 10, fd)) : (write(fd, "-", 1));
	buff = '0' + nbr % 10;
	write(fd, &buff, 1);
	return (0);
}

int			ft_putnbr_fd(int nbr, int fd)
{
	long int	buff;

	buff = '0';
	if (nbr < 0)
		return (ft_putnbr_neg_fd(-(long int)nbr, fd));
	(nbr % 10 != nbr) ? (ft_putnbr_fd(nbr / 10, fd)) : buff;
	buff = '0' + nbr % 10;
	write(fd, &buff, 1);
	return (0);
}
