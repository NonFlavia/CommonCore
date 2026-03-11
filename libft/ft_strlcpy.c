/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:08:40 by flavides          #+#    #+#             */
/*   Updated: 2025/12/20 18:18:30 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strlcpy() function copies up to size - 1 characters 
 * from the NUL-terminated
 * string src to dst, NUL-terminating the result.
 * it returns the the length of src.*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main()
{
	// char src[8] = "EhyFla";
	char	*dest;
	dest = (char *)malloc(sizeof(*dest) * 15);
	if (! dest)
	{
		printf ("mammeta\n");
		return (0);
		}
	printf ("%zu \n %s\n", ft_strlcpy(dest, "lorem ipsum", 3), dest);
	return (0);
} */
