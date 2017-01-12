/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:32:06 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/04 00:56:42 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_int_len(int n, int len)
{
	if (n && (n % 10 != n))
	{
		((n % 10 != n) ? (len = ft_int_len(n / 10, (len + 1))) :
			(len = len + 1));
	}
	return (len);
}

static char	*ft_itoa_to_big(void)
{
	size_t		pos;
	char		*buff;

	buff = (char*)malloc(sizeof(char) * 2);
	if (!buff)
		return (NULL);
	pos = 1;
	buff[pos--] = 0;
	buff[pos] = '0';
	return (buff);
}

static char	*ft_itoa_neg(long int n2)
{
	size_t		pos;
	char		*buff;
	int			end;

	end = 0;
	pos = ft_int_len(n2, 2);
	buff = (char*)malloc(sizeof(char) * (pos + 1));
	if (!buff)
		return (NULL);
	buff[pos--] = 0;
	buff[0] = '-';
	while (end != 1)
	{
		buff[pos--] = n2 % 10 + '0';
		((n2 % 10 == n2) ? (end = 1) :
			(n2 = n2 / 10));
	}
	return (buff);
}

char		*ft_itoa(int n)
{
	size_t		pos;
	char		*buff;
	int			end;
	long int	n2;

	n2 = (long int)n;
	end = 0;
	if (n2 > 0 && n2 <= 2147483647)
	{
		pos = ft_int_len(n2, 1);
		buff = (char*)malloc(sizeof(char) * (pos + 1));
		if (!buff)
			return (NULL);
		buff[pos--] = 0;
		while (end != 1)
		{
			buff[pos--] = n2 % 10 + '0';
			((n2 % 10 == n2) ? (end = 1) :
				(n2 = n2 / 10));
		}
		return (buff);
	}
	else if (n2 < 0 && n2 >= -2147483648)
		return (ft_itoa_neg(-n2));
	return (ft_itoa_to_big());
}
