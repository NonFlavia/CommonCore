#include <stdlib.h>

// hi, this code was made by flavides during the 42 Common Core!

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
