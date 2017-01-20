
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*map;

	map = (char *)malloc(sizeof(char) * 4);
	map = "bad bitch !";
	map[0] = 'm';
	printf("%s\n", map);
	return (0);
}
