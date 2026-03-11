/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:56:20 by flavides          #+#    #+#             */
/*   Updated: 2025/11/27 21:41:17 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (! s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int	main()
{
	printf("%zu lunghezza stringa\n", ft_strlen(NULL));
	return (0);
}*/
