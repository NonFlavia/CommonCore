/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:34:18 by flavides          #+#    #+#             */
/*   Updated: 2026/01/29 14:47:04 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* cerca sotto stringa da:
 * punto (start) della stringa (*s)
 * la len della sub str e' (len)
 * res la str trovata o NULL se fa tutto schifo

usato strlcpy da s in pos start fino a len, saved in tosave */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*tosave;
	size_t	strlen;

	strlen = ft_strlen(s);
	if (! s)
		return (NULL);
	if (len > strlen - start)
		len = strlen - start;
	if (start > strlen)
	{
		tosave = malloc(1);
		tosave[0] = '\0';
		return (tosave);
	}
	tosave = (char *)malloc(len + 1);
	if (! tosave)
		return (NULL);
	ft_strlcpy(tosave, &s[start], len + 1);
	return (tosave);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("manca argomento da copiare\n");
		return (1);
	}
	printf(" from %s\n from ch %d\n to %d\n", argv[1], 3, 4);
	printf("result: %s\n", ft_substr(argv[1],3,4));
	return (0);
}*/
