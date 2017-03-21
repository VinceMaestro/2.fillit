/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/21 16:29:44 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
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

static void	ft_getstr(int open_fd, char **line)
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

static char	*ft_display_file(char *argv)
{
	int			open_fd;
	char		**line;

	open_fd = open(argv, O_RDWR);
	if (open_fd == -1)
		ft_error();
	line = (char**)malloc(sizeof(char*));
	if (line)
		ft_getstr(open_fd, line);
	if (close(open_fd) == -1)
		ft_error();
	if (!line)
		ft_error();
	return (*line);
}

int			main(int argc, char **argv)
{
	char		*line;
	t_matrix	*matrix;
	int			piece_nb;

	piece_nb = 0;
	if (argc == 2)
	{
		line = ft_display_file(argv[1]);
		piece_nb = ft_reader(line);
		matrix = ft_matrix_maker(line, piece_nb);
		matrix = ft_transform("ALL", matrix, piece_nb);
		matrix = ft_getbestshape(matrix);
		ft_map(matrix);
	}
	else
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
		return (-1);
	}
}
