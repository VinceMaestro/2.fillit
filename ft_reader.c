/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:01:57 by ilarbi            #+#    #+#             */
/*   Updated: 2017/01/12 22:47:10 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "fillit.h"

static	int	ft_isvalid_char(char c)
{
	return ((c == '#' || c == '.') ? 1 : 0);
}

static	int	ft_isvalid(char *input)
{
	//lit fichier , verifie qu il est conforme
	//retourne 0 si non, nbre pieces si oui
	int		i;
	int		j;
	int		diese;

	i = 0;
	j = 0;
	diese = 0;
	while (*input)//file
	{
		while (*input && (!*(input + 1) || *(input + 1) != '\n'))//bloc
		{
			while (*input != '\n' && ft_isvalid_char(*input))//line
			{
				((*input == '#') ? diese++ : diese);
				printf("*input = %c\n j = %i\n", *input, j);
				input++;
				j++;
			}
			if (j != 4 || *input != '\n')
			{
				printf("fichier non valie j = %d *input = %c\n", j, *input);
				ft_error ("fichier non valide\n");
			}
			printf("*input de fin : %c\n", *input);
			input++;//passer du \n a la ligne vide
			j = 0;
			i++;
		}
		if (diese != 4 || i != 4)
		{
			printf("fichier non valide: diese = %d i = %d\n", diese, i);
			exit(1);
		}
		diese = 0;
		i = 0;
		input++;//2e \n ou \0
		printf("*input boffff %c\n", *input);
		if (!*(input))
		   return (i + 1);

	}
	return (0);
	printf("chaine null ou vide\n");
	exit(1);
	//ft_error("chaine null ou vide\n");//exits pgm
}

int		ft_reader(char	*input)
{
	if (input)
	{
		ft_putnbr(ft_isvalid(input));
	}
	else
		exit(1);
	return (0);//ou 1 en cas de succes
}

/*int		main(void)
{

	char *input = "##..\n##..\n....\n....\n\n####\n....\n....\n....";
	printf("%d\n", ft_isvalid(input));
	return (0);
}*/
