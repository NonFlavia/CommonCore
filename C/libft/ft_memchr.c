/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:34:18 by flavides          #+#    #+#             */
/*   Updated: 2026/02/09 19:37:42 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//compara due aree della memoria... the end
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*str;
	unsigned char			pasqua;

	str = (const unsigned char *)s;
	pasqua = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == pasqua)
			return ((void *)&str[i]);
		i++;
	}
	return ((void *) NULL);
}
/* 
int	main()
{
	char str[20] = "";
	printf ("corr i trovy %s\n", (char *)ft_memchr(str + 11, 'i', 20));
}*/
