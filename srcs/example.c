#include <stdio.h>
#include <string.h>
#include <limits.h>

int			main(int ac, char **av)
{
	char	*max = "2147483647";
	char	*min = "-2147483648";
	printf("difference: %d\n", strcmp(max, av[1]));
	return (0);
}
