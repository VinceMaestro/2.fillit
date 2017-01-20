#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct	s_piece
{
	char 		*tetri;
	char 		name;
}				t_piece;
//tests if there are as much points as shape takes
char	*ft_overlap(char *position, int size)
{
	int		i;
	
	i = 1;
	while (i < size)
	{
		if (position[i] == '.')
		   i++;	
	}
	return ((i == size) ? (&position[i]) : NULL);
}

char    *ft_strtrimpiece(char const *s)
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

	tab[count].tetri = ft_strtrimpiece(shape);
	tab[count].name = 'A' + count;
	count++;
	return (tab);
}
//parcours chaine map jusqu a trouver assez de vide pr lacer chaine shape
char	*ft_place(char *map, t_piece p)
  {
	  int	size;
	  int	i;
	char	*search;	
			
		i = 0;	
	  size = ft_strlen(p.tetri);
	  search = map;
	  printf("taille shape : %d\n", size);
	  while(search[i] && search[i] != '.')
		  i++;
	 if (search[i] == '.')
	 {
		 printf("overlap returns : %p", ft_overlap(&search[i], size));
		ft_memcpy(&search[i], p.tetri, size);
		printf("ma nouvelle map : %s\n", map);
	 }return (map);
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
	shape = "####\n....\n....\n....\n";
	map = (char *)malloc(sizeof(char) * 4);
	map = "....";
	ft_new_piece(tab, shape);
	printf("shape : %s     name : %c\n", tab[i].tetri, tab[i].name);

	printf("%s\n", ft_place(map, tab[i]));
	return (0);
}

