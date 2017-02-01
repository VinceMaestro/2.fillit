/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/02/01 04:11:33 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>

char	*ft_display_file(char *argv)
{
	int			open_fd;
	char		**line;

	open_fd = open(argv, O_RDWR);
	if (open_fd == -1)
		ft_error("FT_DISPLAY_FILE: open file () failed \n");
	line = (char**)malloc(sizeof(char*));
	if (line)
		ft_getstr(open_fd, line);
	if (close(open_fd) == -1)
		ft_error("FT_DISPLAY_FILE: close file () failed \n");
	if (!line)
		ft_error("FT_DISPLAY_FILE: line malloc failed");
	return (*line);
}

int			main(int argc, char **argv)
{
	char		*line;
	t_matrix	*matrix;
	int			dim;

	dim = 0;
	ft_putstr(":INFO: MAIN: Fillit program Start\n");
	if (argc == 1)
	{
		ft_error("MAIN: File name missing.\n");
		return (-1);
	}
	else if (argc == 2)
	{
		line = ft_display_file(argv[1]);
		dim = ft_roundup_sqrt(4 * ft_reader(line));
		ft_putnbr(dim);
		matrix = ft_matrix_maker(line, dim);
		matrix = ft_transfallmatrix(matrix);

		ft_getbestshape(matrix);
		ft_putstr(":INFO: MAIN: Fillit program End\n");
	}
	else
		ft_error("MAIN: Too many arguments.\n");
	return (-1);
}
