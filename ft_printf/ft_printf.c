/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:57:51 by flavides          #+#    #+#             */
/*   Updated: 2026/03/03 17:00:38 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	istheend(va_list ap, const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '%' && str[i + 1] == '\0')
	{
		va_end(ap);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		returnvalue;
	int		iter;
	va_list	ap;

	returnvalue = 0;
	iter = 0;
	va_start(ap, str);
	while (str && str[iter] != '\0')
	{
		while (str[iter] != '%' && str[iter] != '\0')
		{
			returnvalue += write (1, &str[iter], 1);
			iter++;
		}
		if (str[iter] == '%' && str[iter + 1] != '\0')
		{
			returnvalue += ft_handlecases(str[iter + 1], &ap);
			iter += 2;
		}
		if (istheend(ap, &str[iter]))
			return (returnvalue);
	}
	va_end(ap);
	return (returnvalue);
}
/*
int	main()
{
	int n;
    int num;
	char *p;
    p = NULL;
	n = ft_printf("%s", p);
    num = printf ("%s", p);
	printf("\nchar stampati %d\n%d printf originnal\n", n, num);
	return (0);
} */
