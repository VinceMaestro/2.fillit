/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:01:48 by ilarbi            #+#    #+#             */
/*   Updated: 2017/01/21 20:49:08 by ilarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct	s_piece
{
	char 		*tetri;
	char 		name;
}				t_piece;

static	char	*ft_shape(const char *shape, int dim)
{
	int		i;
	char	*dimshape;
	char	*start;
	int		line;
	
	dimshape = (char*)malloc(sizeof(char) * ((dim + 1) * dim));
	start = dimshape;
	line = 0;
	while (dim > 4 && i < dim)
	{

		if ((*shape == '#') || (*shape == '.'))
		{
			//*dimshape++ = *shape++;
			ft_memset(dimshape, *shape, 1);
			printf(" i = %d :  %c\n" ,i,  *dimshape);
			dimshape++;
			shape++;
			i++;

		}
		if (*shape == '\n' && i < dim)
		//	*dimshape++ = '.';
		{
			ft_memset(dimshape, '.', 1);
			printf(" i = %d :  %c\n" ,i,  *dimshape);
			dimshape++;
		//	shape++;
			i++;
		}
		if (i == dim)
		{
			//*dimshape++ = '\n';
			ft_memset(dimshape, '\n', 1);
			line++;
			printf(" i = %d :  %c\n" ,i,  *dimshape);
			dimshape++;
			shape++;
			i = 0;
		}
			while (!*shape && line < dim)
			{
				ft_memset(dimshape,'.', dim);
				ft_memset(dimshape + dim , '\n', 1);
				//printf("ligne ajoutee : %s", dimshape -dim -1);
				line++;
				i = line;
				dimshape = dimshape + dim + 1;
			}
	}
	return (start);
}
//tests if there are as much points as shape takes
static	int		ft_overlap(char *position, int size)
{
	int		i;
	
	i = 1;
	while (i < size && position[i] && position[i] == '.')
		   i++;	
	return ((i == size) ? 0 : 1);
}

static	char    *ft_strtrimpiece(char const *s)
{
	int     start;
	int     end;
	int     len;
	char    *fresh;

	start = 0;
	fresh = NULL;
	if (s)
	{
		end = ft_strlen(s) - 1;
		while (s[start] == '.' || s[start] == '\n')
			start++;
		while (s[end] == '.' || s[end] == '\n')
			end--;
		((start > end) ? (len = 1) :
		 (len = end - start + 2));
		fresh = (char *)malloc(sizeof(char) * (len));
		if (fresh != NULL)
		{
			ft_memcpy(fresh, &s[start], len - 1);
			fresh[len - 1] = '\0';
		}
	}
	return (fresh);
}

t_piece	*ft_new_piece(t_piece tab[26], char const *shape)
{
	static	int	count = 0;
	int			index;

	index = 0;
	tab[count].tetri = ft_strtrimpiece(shape);
	printf("tab[0].count.tetri = \n%s\n", tab[count].tetri);
	tab[count].name = 'A' + count;
	while (tab[count].tetri[index])
	{
		if (tab[count].tetri[index] == '#')
			tab[count].tetri[index] = tab[count].name;
		index++;
	}	
	count++;
	return (tab);
}
//parcours chaine map jusqu a trouver assez de vide pr lacer chaine shape
int		ft_place(char **map, t_piece p)
  {
	  int	size;
	  int	i;

		i = 0;	
	  size = ft_strlen(p.tetri);
	  printf("ma map bitch ! %s\n", *map);
	  printf("taille shape : %d\n", size);
	while (*map[i] && *map[i] != '.')
  		i++;
	 if (*map[i] == '.')
	 {
		 if(!ft_overlap(*map + i, size))
		 {	
			 ft_memcpy(*map + i, p.tetri, size);
			printf("=========ma nouvelle map : \n%s \n=========", *map);
	 		return (1);
		 }
	 }
	 return (0);
  }
/*
   int  ft_solve(char *map, struct *piece)
   {

   }
   */
int		main(void)
{
	int			i;
	char const	*shape;
	t_piece 	tab[26];
	char		*map;
	
	i = 0;
	shape = ".##.\n##..\n....\n....\n";
	map = (char *)malloc(sizeof(char) * 20);
	ft_strcpy(map, "....\n....\n....\n....\n");
	ft_new_piece(tab, shape);
	printf("shape : %s     name : %c\n", tab[i].tetri, tab[i].name);
	//if (!ft_place(&map, tab[i]))
	//	ft_putstr("map too small");
	printf("new format :\n%s", ft_shape(shape, 15));
	return (0);
}

