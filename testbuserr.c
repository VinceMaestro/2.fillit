
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

int	main(void)
{
	char	*map;

	map = (char *)malloc(sizeof(char) * 4);
	ft_strcpy(map, "bad bitch!");
	printf("%s\n", map);
	return (0);
}
