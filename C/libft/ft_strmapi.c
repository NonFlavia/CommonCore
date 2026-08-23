/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:49:33 by flavides          #+#    #+#             */
/*   Updated: 2026/01/29 14:51:39 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to store the
results from the successive applications of f. 
f(i, s) passo l-indice di i da checkare con s*/
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*strnew;
	unsigned int	i;

	i = 0;
	if (! s)
		return (NULL);
	strnew = ft_calloc(ft_strlen(s) + 1, 1);
	while (s[i] != '\0' && strnew && s)
	{
		strnew[i] = f(i, s[i]);
		i++;
	}
	return (strnew);
}
/*
char to_upper(unsigned int i, char c) {
	i = 32;
    if (c >= 'a' && c <= 'z')
        return c - i;
    return c;
}
int	main()
{
	char *str = "yoyoyo che bella vita\n";
	printf ("%s\n", ft_strmapi(str, to_upper));
	printf ("mammeta\n");
}*/
