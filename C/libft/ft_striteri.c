/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:50:15 by flavides          #+#    #+#             */
/*   Updated: 2026/02/01 17:03:35 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* s: The string to iterate over.
f: The function to apply to each character
Applies the function ’f’ to each character of the
string passed as argument, passing its index as
the first argument. Each character is passed by
address to ’f’ so it can be modified if necessary.
			     indirizzo fn*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	to_upper(unsigned int i, char *str)
{

	if (i != 0)
	{
		if (str[i - 1] <= 'z' && str[i - 1] >= 'a')
			str[i - 1] -= 32;
	}
	if (i == 0 || i == ft_strlen(str) - 1)
		str[i] -= 32;
}

int	main()
{
	char stringa[16] = "ciao buongiorno";
	printf("%s normale \n", stringa);
	ft_striteri(stringa, to_upper);
	printf("%s mod con striteri", stringa);
	return (0);
} */
