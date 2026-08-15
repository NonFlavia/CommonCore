#include <unistd.h>

// hi, this code was made by flavides during the 42 Common Core!

int	already_printed(char *s, int index, char c)
{
	int	j;

	j = 0;
	while (j < index && s[j])
	{
		if (s[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!already_printed(av[1], i, av[1][i]))
				write(1, &av[1][i], 1);
			i++;
		}
		len = i;
		while (av[2][j])
		{
			if (!already_printed(av[2], j, av[2][j])
				&& !already_printed(av[1], len, av[2][j]))
				write(1, &av[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
