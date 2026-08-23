// hi, this code was made by flavides during the 42 Common Core!

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int				i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result = result << 1;
		result = result | (octet & 1);
		octet = octet >> 1;
		i++;
	}
	return (result);
}
