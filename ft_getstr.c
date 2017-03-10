/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:09:41 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/10 18:13:17 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

static void	*ft_memincr(void *src, int new_size)
{
	void	*buff;

	buff = (void*)malloc(sizeof(void) * (new_size + 1));
	if (buff)
	{
		ft_bzero(buff, new_size + 1);
		if (src)
			ft_memcpy(buff, src, new_size);
	}
	else
		ft_error();
	return (buff);
}

void		ft_getstr(int open_fd, char **line)
{
	int		len;
	int		full_len;
	int		reader;
	char	*str;
	char	*tmp;

	len = 0;
	full_len = len;
	reader = len;
	while (reader == len)
	{
		tmp = str;
		len += 1;
		full_len += len;
		str = ft_memincr(str, full_len);
		ft_strdel(&tmp);
		if (reader == 0)
			reader = read(open_fd, &str[0], len);
		else
			reader = read(open_fd, &str[full_len - len], len);
	}
	tmp = str;
	str = ft_memincr(str, full_len - len + reader);
	*line = str;
	ft_strdel(&tmp);
}
