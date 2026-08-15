// hi, this code was made by flavides during the 42 Common Core!
// remember: strcpy HAS TO cause a buffer overflow if dest is too small!
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
