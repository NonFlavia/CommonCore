/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:33:05 by flavides          #+#    #+#             */
/*   Updated: 2026/02/05 17:40:18 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	istheone;
	size_t	left;
	char	*ptrl;
	char	*ptrb;

	istheone = 0;
	if (*little == '\0' && little)
		return ((char *)big);
	if (!big || !little || len <= 0)
		return (NULL);
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	while (big[istheone] && len > istheone)
	{
		ptrb = (char *)big + istheone;
		ptrl = (char *)little;
		left = len - istheone;
		while (left > 0 && *ptrb == *ptrl && *ptrl && ptrl++ && ptrb++)
			left--;
		if (*ptrl == '\0')
			return ((char *)big + istheone);
		istheone++;
	}
	return (NULL);
}
/*
int	main()
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "cd";
	size_t len = 8;
	char *result = ft_strnstr(haystack, needle, len);
	printf ("%s trovato?\n", result);
}*/
