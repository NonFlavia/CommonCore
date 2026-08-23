/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:34:39 by flavides          #+#    #+#             */
/*   Updated: 2025/12/02 15:27:44 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*devono essere NUL terminated sia src che dst*/

#include "libft.h"
// size e' la size del buffer dest
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;
	size_t	space;

	i = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size == 0)
		return (lsrc);
	if (ldst >= size)
		return (lsrc + size);
	space = size - ldst -1;
	while (i < space && src[i] != '\0' && src)
	{
		dst[ldst + i] = src[i];
		i++;
	}
	dst[ldst + i] = '\0';
	return (ldst + lsrc);
}
/*
int	main()
{
	char flavia[14] = "        ";
	char src[3] = "yo";
	printf("%zu numeri ragazzi \n", ft_strlcat(flavia,src,14));
}*/
