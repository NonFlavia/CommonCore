/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:09:37 by flavides          #+#    #+#             */
/*   Updated: 2025/12/02 15:25:01 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The bzero() function erases the data in the n bytes of the memory
       starting at the location pointed to by s, by writing zeros (bytes
       containing '\0') to that area. */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	c;

	c = '\0';
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
}
/* 
int	main()
{
	int	i;
	
	i = 0; //'\0' '\0' '\0' '\0' ' ' 'F' 'l' 'a'
	char stringa[8] = "Ciao Fla";
	char c = 92;
        // bzero(stringa, 4);
	ft_bzero(stringa, 4); // non va fino a 4, nun sacc pekkkeeee
	while (i < 4)
	{
		if (stringa[i] == '\0')
		{
			write (1, &c, 1);
			write (1, "0", 1);
			i++;
		}
	}
	while (i < 8 && stringa[i] !='\0')
	{
		write (1, &stringa[i], 1);
		i++;
	}
 
	return (0);
	
} */
