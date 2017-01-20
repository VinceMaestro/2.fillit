
#include <stdio.h>

int	test()
{
	static	int	i = 0;

	i++;
	return (i);
}

int  main(void)
{
	int i;

	i = 0;
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	return (0);
}
