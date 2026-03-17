/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:50:12 by flavides          #+#    #+#             */
/*   Updated: 2025/11/29 17:50:54 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// trova ultima ricorrenta di int c (ma e' un char) in s

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	lstr;
	unsigned int	i;
	unsigned char	pippo;

	lstr = ft_strlen(s);
	i = 0;
	pippo = (unsigned char) c;
	while (lstr != i && s && s[lstr] != pippo)
		lstr--;
	if ((! s) || (s[lstr] != pippo))
		return (NULL);
	return ((char *)&s[lstr]);
}
/*
int	main()
{
	char str[14] = "FlAAAAquartaa";
	
	printf("lultima ricorrenza e' %s\n", ft_strrchr(str,'A'));

} */
