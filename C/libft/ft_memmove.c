/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:50:34 by flavides          #+#    #+#             */
/*   Updated: 2025/12/02 15:26:24 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La funzione memmove() copia n byte dall'area di memoria src
 *  all'area di memoria dest. Le aree di memoria possono sovrapporsi: 
 *  la copia avviene come se i byte in src venissero prima copiati 
 *  in un array temporaneo */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!dest && !src)
		return (NULL);
	tmp = (char *)src;
	if ((char *)dest < (char *)src)
	{
		while (i < n)
		{
			((char *)dest)[i] = tmp[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			((char *)dest)[n] = tmp[n];
		}
	}
	return (dest);
}
/*
int	main()
{
	char src[12] = "ueuaglio";
	char dst[5] = "ciao";
	ft_memmove(dst, src, 3);
	printf("la stringa restituita e' %s\n", dst);
	return (0);
} */
