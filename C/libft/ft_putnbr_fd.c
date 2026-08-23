/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:51:02 by flavides          #+#    #+#             */
/*   Updated: 2026/02/11 18:17:31 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* converte un numero to fd */
void	ft_putnbr(int nb, int fd)
{
	char	c;
	long	v;

	v = nb;
	if (v < 0)
	{
		v = -v;
		write (fd, "-", 1);
	}
	if (v >= 0 && v <= 9)
	{
		c = (v % 10) + 48;
		write (fd, &c, 1);
	}
	else
	{
		ft_putnbr(v / 10, fd);
		ft_putnbr (v % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
