/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:45:00 by flavides          #+#    #+#             */
/*   Updated: 2026/02/05 17:44:44 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* itoa

NON FUNZIONANO LE UNIT' 
e; una triste storia
 * converte un intero in un ascii 
 * Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled.*/
#include "libft.h"

size_t	ft_howlong(long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	else if (nb == 0)
		len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	if (nb > 0 && nb < 10)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	long	numb;
	long	sign;
	long	lnumb;
	char	*string;

	numb = (long)n;
	sign = 0;
	lnumb = ft_howlong(numb);
	string = (char *)ft_calloc(lnumb + 1, 1);
	while (lnumb > sign)
	{
		lnumb--;
		if (numb < 0)
		{
			numb = numb * -1;
			string[0] = '-';
			sign = 1;
		}
		string[lnumb] = (numb % 10) + '0';
		if (numb > 9)
			numb = numb / 10;
	}
	return (string);
}
/*
int	main()
{

	
	printf("%s\n", ft_itoa(-2147483648));
}*/
