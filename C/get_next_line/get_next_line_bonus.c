/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:04:06 by flavides          #+#    #+#             */
/*   Updated: 2026/04/10 17:04:08 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 4096)
		return (NULL);
	str[fd] = ft_readandsave(fd, str[fd]);
	if (! str[fd])
		return (NULL);
	line = ft_getline(str[fd]);
	str[fd] = ft_getrest(str[fd]);
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
}*/
