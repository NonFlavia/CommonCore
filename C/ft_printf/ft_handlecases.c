/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlecases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:23:15 by flavides          #+#    #+#             */
/*   Updated: 2026/03/03 15:24:05 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointers(va_list *ap)
{
	unsigned long	apnumb;
	int				returnvalue;
	const char		*exatablemin;

	apnumb = (unsigned long)va_arg(*ap, void *);
	returnvalue = 0;
	exatablemin = "0123456789abcdef";
	if (apnumb == 0)
		return (returnvalue += write(1, "(nil)", 5));
	returnvalue += write (1, "0x", 2);
	returnvalue += ft_itoapointers(apnumb, exatablemin);
	return (returnvalue);
}

int	ft_exapointers(char c, va_list *ap)
{
	const char	*exatable;
	const char	*exatablemin;
	int			returnvalue;
	int			apnumb;

	exatable = "0123456789ABCDEF";
	exatablemin = "0123456789abcdef";
	returnvalue = 0;
	apnumb = 0;
	if (c == 'x')
	{
		apnumb = va_arg(*ap, unsigned int);
		returnvalue += ft_itoaexa(apnumb, exatablemin);
	}
	else if (c == 'X')
	{
		apnumb = va_arg(*ap, unsigned int);
		returnvalue += ft_itoaexa(apnumb, exatable);
	}
	else if (c == 'p')
		returnvalue += ft_pointers(ap);
	return (returnvalue);
}

int	ft_complicatednum(char c, va_list *ap)
{
	int			returnvalue;
	long		apnumb;

	apnumb = 0;
	returnvalue = 0;
	if (c == 'd' || c == 'i')
	{
		apnumb = va_arg(*ap, int);
		returnvalue += ft_itoaprint((long)apnumb);
	}
	else if (c == 'u')
	{
		apnumb = va_arg(*ap, unsigned int);
		returnvalue += ft_itoaprint((unsigned int)apnumb);
	}
	return (returnvalue);
}

int	ft_handlecases(char type, va_list *ap)
{
	char	*aptocpy;
	int		returnvalue;
	char	found;

	aptocpy = NULL;
	returnvalue = 0;
	if (type == 's')
	{
		aptocpy = va_arg(*ap, char *);
		returnvalue += ft_putstr(aptocpy);
	}
	else if (type == 'c')
	{
		found = va_arg(*ap, int);
		returnvalue = (int)write(1, &found, 1);
	}
	else if (type == '%')
		returnvalue += (int)write(1, "%", 1);
	else if (type == 'd' || type == 'i' || type == 'u')
		returnvalue += ft_complicatednum(type, ap);
	else if (type == 'x' || type == 'X' || type == 'p')
		returnvalue += ft_exapointers(type, ap);
	return (returnvalue);
}
