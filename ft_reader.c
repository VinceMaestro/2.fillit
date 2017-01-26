/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <ilarbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:01:57 by ilarbi            #+#    #+#             */
/*   Updated: 2017/01/26 18:31:42 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

static	int	ft_isvalid_char(char c)
{
	return ((c == '#' || c == '.') ? 1 : 0);
}

static	int	ft_isvalid(char *input)
{
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
				//((*input == '#') ? diese++ : (*input = '0'));
				printf(" %c ", *input);
				input++;
				j++;
			}
			if (j != 4 || *input != '\n')
				exit(1);//ft_error("fichier non valide : colonnes\n");exit
			printf("%c", *input);
			input++;//passer du \n a la ligne vide
			j = 0;
			i++;
		}
		if (diese != 4 || i != 4)
			exit(1);//ft_error("fichrer non valide: diese ou lignes\n");
		else
			printf("bloc valide\n");
		pieces++;
		diese = 0;
		i = 0;
		if (*input == '\0')
		   return (pieces);
		input++;//1er char bloc suiv.
	}
	ft_putstr("chaine null ou vide\n");
	return (0);
}

static int	ft_scan_bloc(char **tmp)
{
	int	i;
	int	j;
	int	count;
	int ret;

	i = 0;
	j = 0;
	count = 0;
	ret = 0;
	while (i < 4)
	{
		if (tmp[i][j] == '#')
		{
			ret = ft_isvalid_shape(tmp, i, j, &count);
			printf("isvalidshape = %d\n", ret);
			//break;
			return (ret);
		}
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
	}
	return (0);
}

static int	ft_scan_pieces(char **bloc, int pieces)
{
	int		i;
	int		j;
	int		k;
	int		line;
	char	**tmp;

	i = 0;
	j = 0;
	k = 1;
	line = 0;
	tmp = (char **)malloc(sizeof(char *) * 5);
	tmp[4] = 0;
	while (i < 4 * k && k <= pieces)
	{
		while (line < 4)
		{
			tmp[line] = (char *)malloc(sizeof(char *) * 5);
			tmp[line++] = bloc[i++];
		}
		if (!ft_scan_bloc(tmp))
			exit(1);
	//	while (line >= 0 && i >= 4 * (k - 1))
	//		bloc[i--] = tmp[line--];
		i = 4 * k;
		k++;
		j = 0;
		line = 0;
	}
	return (1);
}

int			ft_reader(char *input)
{
	int		pieces;
	char	**bloc;

	if (input)
	{
		pieces = ft_isvalid(input);
		if (pieces == 0)
			exit(1);
		else
			printf("je dispose de %d pieces\n", pieces);
		bloc = ft_strsplit(input, '\n');
		if (!ft_scan_pieces(bloc, pieces))
			exit(1);
		return (pieces);
	}
	return (0);
}
//
// int		main(void)
// {
//
// 	char *input = "##..\n##..\n....\n....\n\n####\n....\n....\n....\n\n##..\n#...\n#...\n....\n";
// 	/*printf("Your input is : \n%s\n", input);
// 	printf("ft_reader return : \n");*/
// 	printf("reader retourne %d\n", ft_reader(input));
// 	return (0);
// }
