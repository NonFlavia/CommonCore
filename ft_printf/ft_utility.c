/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:58:07 by flavides          #+#    #+#             */
/*   Updated: 2026/03/03 16:58:09 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *toprint)
{
	int	i;

	i = 0;
	if (! toprint)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	while (toprint && toprint[i] != '\0')
	{
		write(1, &toprint[i], 1);
		i++;
	}
	return (i);
}

int	ft_itoapointers(unsigned long nb, const char *exacase)
{
	char	c;
	int		returnvalue;

	returnvalue = 0;
	if (nb > 15)
		returnvalue += ft_itoapointers(nb / 16, exacase);
	c = exacase[nb % 16];
	returnvalue += (int)write(1, &c, 1);
	return (returnvalue);
}

int	ft_itoaexa(unsigned int nb, const char *exacase)
{
	char	c;
	int		returnvalue;

	returnvalue = 0;
	if (nb > 15)
		returnvalue += ft_itoaexa(nb / 16, exacase);
	c = exacase[nb % 16];
	returnvalue += (int)write(1, &c, 1);
	return (returnvalue);
}

int	ft_itoaprint(long nb)
{
	char	c;
	int		returnvalue;

	returnvalue = 0;
	if (nb < 0)
	{
		returnvalue += (int)write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		returnvalue += ft_itoaprint(nb / 10);
	c = nb % 10 + '0';
	returnvalue += (int)write(1, &c, 1);
	return (returnvalue);
}
