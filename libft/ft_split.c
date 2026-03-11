/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:59:15 by flavides          #+#    #+#             */
/*   Updated: 2026/02/05 17:30:35 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// calcola la lung di una stringa

void	ft_freesplitted(char **splitted, size_t j)
{
	while (j > 0)
	{
		j--;
		free(splitted[j]);
	}
	free(splitted);
}

size_t	ft_isaword(const char *s, char c)
{
	size_t	i;
	size_t	howmanytimes;

	if (!s)
		return (0);
	i = 0;
	howmanytimes = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			howmanytimes++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (howmanytimes);
}
/* size_t	j; // iteratore di splitted
	size_t	i; // per copiare in ft_substr le varie parole
	size_t	howmanytimes; //quante volte fare la copia 
	size_t	start // di volta in volta salvare start;
	size_t len; // di volta in volta salvare len come pos i - start
	
	split non e' una matrice ma un array di pointers,
	quindi basta allocarlo come size of char * numero di parole + 1 '\0'
	importante! siccome in split creiamo fuori da **splitted delle stringhe
	a cui puntano i puntatori di **splitted, dobbiamo liberare la memoria
	nel caso in cui il processo fallisca nel mezzo :)
	*/

char	**ft_split(const char *s, char c)
{
	char	**splitted;
	size_t	j;
	size_t	i;
	size_t	start;

	i = 0;
	j = 0;
	splitted = (char **)ft_calloc((ft_isaword(s, c) + 1), sizeof(char *));
	while (j < ft_isaword(s, c))
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		splitted[j] = ft_substr(s, (unsigned int)start, i - start);
		if (! splitted[j])
		{
			ft_freesplitted(splitted, j);
			return (NULL);
		}
		j++;
	}
	splitted[j] = NULL;
	return (splitted);
}
/*
int	main()
{
	//size_t i = 0;

	char	**split;
		split = ft_split("", 'z');
	printf("%s split 1\n%s split 2\n%s split 3\n", split[0], split[1], split[2]);


	
		
	return (0);
}
*/
