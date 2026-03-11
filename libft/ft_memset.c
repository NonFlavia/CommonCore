/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:04:51 by flavides          #+#    #+#             */
/*   Updated: 2025/12/20 18:08:19 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//setta area di memoria con uno specifico valore char c o int c
// conv void* -> char* con conv. espl., poi i< count, scrive fino a count. 
void	*ft_memset(void *dest, int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((char *)dest)[i] = c;
		i++;
	}
	return ((void *)dest);
}
/*
int main ()
{
  char str[] = "almost every programmer should know memset!";
  char *newstring = ft_memset (str,'-',6);
  printf("%s\n", newstring);
  return 0;
}*/
