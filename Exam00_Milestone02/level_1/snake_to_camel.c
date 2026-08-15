#include <unistd.h>

// hi, this code was made by flavides during the 42 Common Core!

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '_' && argv[1][i + 1])
			{
				i++;
				if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
					argv[1][i] -= 32;
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
