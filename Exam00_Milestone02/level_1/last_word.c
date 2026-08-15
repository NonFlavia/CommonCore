#include <unistd.h>

// hi, this code was made by flavides during the 42 Common Core!

void	last_word(char *str)
{
	int	i;
	int	end;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	end = i;
	while (i >= 0 && str[i] != ' ' && str[i] != '\t')
		i--;
	i++;
	while (i <= end)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
