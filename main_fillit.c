/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/11 18:18:47 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

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
	if (argc == 1)
	{
		ft_error();
		return (-1);
	}
	else if (argc == 2)
	{
		line = ft_display_file(argv[1]);
		piece_nb = ft_reader(line);
		matrix = ft_matrix_maker(line, piece_nb);
		matrix = ft_transform("ALL", matrix, piece_nb);
		matrix = ft_getbestshape(matrix);
		ft_map(matrix);
	}
	else
		ft_error();
	return (-1);
}
