#include <unistd.h>

// hi, this code was made by flavides during the 42 Common Core!

void	print_bits(unsigned char octet)
{
	int	i;

	i = 8;
	while (i--)
		write(1, "01" + ((octet >> i) & 1), 1);
}

// another way to do it:
/*
void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}
*/
