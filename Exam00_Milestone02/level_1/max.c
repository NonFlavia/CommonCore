// hi, this code was made by flavides during the 42 Common Core!

int	max(int *tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	if (len == 0)
		return (0);
	i = 0;
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
