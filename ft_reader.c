/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:01:57 by ilarbi            #+#    #+#             */
/*   Updated: 2017/01/13 13:42:51 by ilarbi           ###   ########.fr       */
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
	int		pieces;

	i = 0;
	j = 0;
	diese = 0;
	pieces = 0;
	while (*input)//file
	{
		while (*input != '\n' && (*input && *(input + 1) != '\n'))//bloc	
		{
			while (*input != '\n' && ft_isvalid_char(*input))//line
			{
				((*input == '#') ? diese++ : diese);
				printf(" %c ", *input);
				input++;
				j++;
			}
			if (j != 4 || *input != '\n')
				ft_error("fichier non valide : colonnes\n");//exits pgm
			printf("%c", *input);
			input++;//passer du \n a la ligne vide
			j = 0;
			i++;
		}
		printf("sortie de bloc\n");
		if (diese != 4 || i != 4)
			ft_error("fichrer non valide: diese ou lignes\n");
		else
			printf("bloc valide\n");
		pieces++;
		diese = 0;
		i = 0;
		if (*input == '\0')
		   return (pieces);
		input++;//2e \n ou \0
	}
	return (0);
	ft_error("chaine null ou vide\n");//exits pgm
}

int		ft_reader(char	*input)
{
	if (input)
	{
		return (ft_isvalid(input));
	}
	return (1);
}

int		main(void)
{

	char *input = "#...\n##..\n....\n....\n\n####\n....\n....\n....\n";
	printf("%d\n", ft_reader(input));
	return (0);
}