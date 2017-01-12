/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:01:57 by ilarbi            #+#    #+#             */
/*   Updated: 2017/01/12 19:07:35 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

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
	while (*input)//file
	{
		while (*(input + 1) || *(input + 1) != '\n')//bloc
		{
			while (*input != '\n' && ft_isvalid_char(*input))//line
			{
				((*input == '#') ? diese++ : diese);
				input++;
				j++;
			}
			if (j > 3 || !ft_isvalid_char(*input) || diese > 4)
			//	ft_error ("fichier non valide\n");//exits pgm
				exit(1);
			diese = 0;
			j = 0;
			i++;
		}
		if (!*(input))
		   return (i + 1);	
	}
	return (0);
	exit(1);//ft_error("chaine null ou vide\n");
}

/*int		ft_reader(char	*input)
{
	if (input)
	{
		ft_putnbr(ft_isvalid(input));
	}
	else
		exit(1);
	return (0);//ou 1 en cas de succes
}*/

int		main(void)
{

	char *input = "##..\n##..\n##..\n....";
	ft_putnbr(ft_isvalid(input));
	return (0);
}
