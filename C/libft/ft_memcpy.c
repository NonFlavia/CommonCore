/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:57:02 by flavides          #+#    #+#             */
/*   Updated: 2026/01/29 15:45:43 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//copia cose in un-area di memoria con buffer n.
//					     n of bytes
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)d);
}
/*
int	main()
{
	char src[] = "copia questo";
	char dst[100];
	memcpy(dest,src, strlen(src) + 1);
	ft_memcpy(dst, src, 2);
	printf("la stringa restituita e' %s\n", dst);
	return (0);
}*/
