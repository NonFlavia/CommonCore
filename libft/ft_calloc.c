/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:02:39 by flavides          #+#    #+#             */
/*   Updated: 2026/01/31 18:48:12 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* alloraaa a differenza di malloc, 
calloc serve ad allocare memoria ad 
oggetti (nmemb -> numero membri) 
ciascuno grande (size -> dim buffer di ciascuno)
Calloc e' figo perche' non lascia popo nella memoria
ma azzera la memoria designata a fare cose
DA QUI, il senso di bzero yeye
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
