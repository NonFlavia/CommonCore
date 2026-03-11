/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:16:40 by flavides          #+#    #+#             */
/*   Updated: 2026/01/31 15:54:22 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 The  strcmp()  function compares the two strings s1 and s2.
 The locale is not taken into account
 The comparison is done using unsigned characters.
 returns an integer indicating the result of the comparison,
 as follows 0, if the s1 and s2 are equal; 
 a negative value if s1 is less than s2;
 positive value if s1 is greater than s2.
The strncmp() function is similar, except it compares  

only  the  first (at most) n bytes of s1 and s2. */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((s1[i] || s2[i]) && i < n))
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i] || (! s2))
			return (1);
		if ((unsigned char)s1[i] < (unsigned char)s2[i] || (! s1))
			return (-1);
		i++;
	}
	return (0);
}
/*
int	main()
{
	printf("= 0, > 1,< -1... %d!!! \n",ft_strncmp("   ", "b", 3));
	// printf("= 0, > 1,< -1 ORI %d!!! \n", strncmp("   ", "b", 3));
	return (0);
}
*/
