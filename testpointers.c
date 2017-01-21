#include <stdio.h>
#include <stdlib.h>

int	ft_overlap(char *pos, int size)
{
	int	i;
	i = 1;
	while (i < size && pos[i] && pos[i] == '.')
			i++;
	return ((i == size) ? 1 : 0);
}

int		main(void)
{
	int		size;
	char	*input;
	char	**map;

	input = "...\n...\n...\n";
	size = 4;
	map = &input;
	printf("%d\n", ft_overlap(*map,size)); 
	return (0);
}
