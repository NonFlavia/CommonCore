/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:40:50 by flavides          #+#    #+#             */
/*   Updated: 2025/11/24 15:23:19 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c) // avevo scritto strisalpha ma agg schbagliat
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
int main()
{
	printf("%d e' un char\n", ft_isalpha('Z'));
	printf("%d e' un int\n", ft_isalpha(9));
	
	return (0);
}*/
