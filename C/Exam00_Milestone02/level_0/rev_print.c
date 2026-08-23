#include <unistd.h>

//hi, this code was made by flavides during the 42 Common Core!

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	rev_print(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_print(argv[1]);
	write(1, "\n", 1);
	return (0);
}
