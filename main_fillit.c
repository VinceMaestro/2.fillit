/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/28 17:01:51 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Test getstr: gcc main_fillit.c ft_getstr.c ./libft/ft_bzero.c ./libft/ft_memcpy.c libft/ft_putstr_fd.c ft_error.c -I libft/libft.h fillit.h

#include "fillit.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

static int	ft_display_file(char *argv)
{
	int			open_fd;
	char		**line;
	t_matrix	*matrix;

	open_fd = open(argv, O_RDWR);
	//On ouvre le fichier passe en parametre
	if (open_fd == -1)
	{
		ft_putstr_fd("open file () failed \n", 2);
		return (-1);
	}
	line = (char**)malloc(sizeof(char*));
	if (line)
	{
		// getstr va passe l'adresse de line, dans laquelle sera stoquee notre ligne
		// envoye *line a ta fonction pour
		ft_getstr(open_fd, line);
		matrix = ft_matrix_maker(*line, ft_reader(*line));
		ft_putstr(": INFO : PRINTING ALL REGISTERED MATRIX");
		while (matrix)
		{
			ft_printmatrix(matrix);
			matrix = matrix->next;
		}
		ft_putstr(": INFO : DONE PRINTING");
		matrix = matrix->first;
		ft_transfallmatrix(matrix);
		//ft_getbestshape(matrix);

	}
	//on ferme le fichier
	if (close(open_fd) == -1)
	{
		ft_putstr_fd("close file () failed \n", 2);
		return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (-1);
	}
	else if (argc == 2)
		return (ft_display_file(argv[1]));
	ft_putstr_fd("Too many arguments.\n", 2);
	return (-1);
}
