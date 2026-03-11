/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:37:36 by flavides          #+#    #+#             */
/*   Updated: 2026/02/05 17:42:29 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ls1s2;
	size_t		i;
	size_t		lbuf;

	i = 0;
	lbuf = ft_strlen(s1) + ft_strlen(s2) + 1;
	ls1s2 = malloc(lbuf);
	if (! ls1s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		ls1s2[i] = s1[i];
		i++;
	}
	ls1s2[i] = '\0';
	ft_strlcat(ls1s2, s2, lbuf);
	return (ls1s2);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 3)
	{	
		write (1, "errore\n", 8);
		return(1);
	}
printf(" s1 %s\n s2%s\n = %s\n", argv[1], argv[2], ft_strjoin(argv[1], argv[2]));
}*/
