//

#include <unistd.h>

// hi, this code was made by flavides during the 42 Common Core!

int	already_seen(char *str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == str[index])
			return (1);
		i++;
	}
	return (0);
}

int	is_inside(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!already_seen(s1, i) && is_inside(s2, s1[i]))
			write(1, &s1[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
