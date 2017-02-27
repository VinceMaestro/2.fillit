/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/27 20:58:26 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_display_file(char *argv)
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
	// ft_putstr("===================================================\n");
	// ft_putstr("::INFO:: -- Start --\t");
	if (argc == 1)
	{
		ft_error();
		return (-1);
	}
	else if (argc == 2)
	{
		// ft_putstr("File :  ");
		// ft_putstr(argv[1]);
		// ft_putstr(" \n");
		// ft_putstr("===================================================\n");
		line = ft_display_file(argv[1]);
		piece_nb = ft_reader(line);
		matrix = ft_matrix_maker(line, piece_nb);
		// ft_putstr("::INFO:: MAIN: -- SUCCESS -- Create Matrix\n");
		// ft_putstr("===================================================\n");
		matrix = ft_transfallmatrix(matrix);
		// ft_putstr("::INFO:: MAIN: -- SUCCESS -- Init Matrix Position\n");
		// ft_putstr("===================================================\n");
		matrix = ft_getbestshape(matrix);
		// ft_putstr("::INFO:: MAIN: -- SUCCESS -- Searching Best Matrix Setup\n");
		// ft_putstr("===================================================\n");
		ft_map(matrix);
		// ft_putstr("::INFO:: MAIN: -- SUCCESS -- Fillit\n");
	}
	else
		ft_error();
	return (-1);
}
