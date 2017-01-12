/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:09:41 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/12 20:27:31 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void	*ft_memincr(void *src, int new_size)
{
	void	*buff;

	printf("memincr ATTEMPT\n");
	buff = (void*)malloc(sizeof(void) * (new_size + 1));
	if (buff)
	{
		ft_bzero(buff, new_size + 1);
		if (src)
		{
			ft_memcpy(buff, src, new_size);
			printf("memincr SUCCESS buff is : %s\n", buff);
		}
	}
	else
		ft_error("memory allocation failed");
	return (buff);
}

void		ft_getstr(int open_fd, char **line)
{
	int		len;
	int		full_len;
	int		reader;
	char	*str;

	len = 0;
	full_len = len;
	reader = len;
	while (reader == len)
	{
		len += 1;
		full_len += len;
		str = ft_memincr(str, full_len);
		if (reader == 0)
			reader = read(open_fd, &str[0], len);
		else
			reader = read(open_fd, &str[full_len - len], len);
	}
	str = ft_memincr(str, full_len - len + reader);
	*line = str;
}
