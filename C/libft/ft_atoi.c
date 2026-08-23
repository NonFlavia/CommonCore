/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:58:46 by flavides          #+#    #+#             */
/*   Updated: 2025/12/20 20:25:59 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//mettere solo in POS 0
int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\a' && c <= '\r' ))
		return (1);
	return (0);
}

//prendere ft_isdigit

int	ft_atoi(const char *nptr)
{
	size_t	i;
	long	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]))
	{
		nbr = (nbr * 10) + nptr[i] - '0';
		i++;
	}
	return (nbr * sign);
}
/*
int	main(int argc, char **argv)
{

	if (argc != 2)
		printf ("gli arg sono pochi, Fla \n");
	else if (argc == 2)
	       printf ("%s ora e' num %d\n", argv[1],ft_atoi(argv[1]));
	return (0);	
}*/
