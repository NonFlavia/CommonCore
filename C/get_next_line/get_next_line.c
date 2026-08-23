/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:36:04 by flavides          #+#    #+#             */
/*   Updated: 2026/04/07 17:06:56 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* get_next_line SEMBRA facile. ma non lo e'.
dove sorge il problema?
Il problema sorge quando il buffer e':
non suffecientemente grande da trovare \n
in quel caso li' cosa dobbiamo fare? 
dobbiamo continuare a leggere 
es. buffer_size 2
[fl av ia \n]
 2  2  2  1-stop
 quanto la riga viene trovata le letture 2 
 vanno aggiunte in una stringa di volta in volta
 strjoin */

#include "get_next_line.h"

char	*ft_getrest(char *str)
{
	char	*rest;
	int		i;

	i = 0;
	rest = NULL;
	if (! str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (! str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	rest = malloc(sizeof(char) * (ft_getlen(str) - i + 1));
	if (! rest)
		return (NULL);
	rest = ft_strtorest(str, rest, &i);
	free (str);
	return (rest);
}

char	*ft_readandsave(int fd, char *str)
{
	char	*buf;
	int		bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (! buf)
		return (NULL);
	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	bytes = 1;
	while (! ft_isanewline(str) && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), free(str), NULL);
		buf[bytes] = '\0';
		str = ft_getstrjoin(str, buf);
	}
	return (free(buf), str);
}

char	*ft_getline(char *str)
{
	char	*line;
	int		i;
	int		tomalloc;

	tomalloc = 0;
	i = 0;
	line = NULL;
	if (! str || ! str[0])
		return (NULL);
	tomalloc = ft_lennewline(str) + 2;
	line = malloc(sizeof(char) * (tomalloc));
	if (! line)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	while (i < tomalloc)
		line[i++] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_readandsave(fd, str);
	if (! str)
		return (NULL);
	line = ft_getline(str);
	str = ft_getrest(str);
	return (line);
}
/*
int main(void)
{
    int     fd;
    char    *line;
	int		linenumb;
	
	linenumb = 0;
    fd = open("text.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Errore apertura file");
        return (1);
    }

    line = get_next_line(fd);
    while (line != NULL)
    {
        linenumb += printf("%s \n", line);
        //printf("%d ", linenumb); 
        
        free(line);
        line = get_next_line(fd);
    }

    close(fd);
    return (0);
}
*/
// qualcosa non mi torna nella stampa caratteri
