/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:35:58 by flavides          #+#    #+#             */
/*   Updated: 2026/04/07 17:23:33 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strtorest(char *str, char *rest, int *i)
{
	int	j;
	int	iter;

	iter = *i;
	j = 0;
	if (! str || ! rest)
		return (NULL);
	while (str[iter])
		rest[j++] = str[iter++];
	rest[j] = '\0';
	return (rest);
}

int	ft_getlen(char *str)
{
	int	len;

	len = 0;
	if (! str)
		return (-1);
	while (str[len])
		len++;
	return (len);
}

int	ft_lennewline(char *str)
{
	int	len;

	len = 0;
	if (! str)
		return (-1);
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

int	ft_isanewline(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_getstrjoin(char *str1, char *str2)
{
	char	*tmp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (ft_getlen(str1) + ft_getlen(str2) + 1));
	if (! tmp)
		return (NULL);
	while (str1 && str1[i])
		tmp[j++] = str1[i++];
	i = 0;
	while (str2 && str2[i])
		tmp[j++] = str2[i++];
	tmp[j] = '\0';
	free(str1);
	return (tmp);
}
