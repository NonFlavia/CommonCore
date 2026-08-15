#include <unistd.h>
// hi, this code was made by flavides during the 42 Common Core!

void	repeat_alpha(char *str)
{
	int	i;
	int	value;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			value = str[i] - 'a' + 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			value = str[i] - 'A' + 1;
		else
			value = 1;
		while (value > 0)
		{
			write(1, &str[i], 1);
			value--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
