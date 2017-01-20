/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/01/19 20:30:41 by ilarbi           ###   ########.fr       */
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
	int		open_fd;
	char	**line;

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
		printf("your string is : \n");
		printf("%s", *line);

		// Ici on appelle ta fonction avec en parametre notre string (la fonction est ok)
		ft_reader(*line);
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
