#include <stddef.h>

// hi, this code was made by flavides during the 42 Common Core!

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j] && s[i] != accept[j])
			j++;
		if (!accept[j])
			return (i);
		i++;
	}
	return (i);
}
