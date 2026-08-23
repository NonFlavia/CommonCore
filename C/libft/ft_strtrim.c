/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:28:46 by flavides          #+#    #+#             */
/*   Updated: 2026/02/05 17:36:19 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	long int	i;
	size_t		lens1;
	char		*trimmed;

	i = 0;
	lens1 = ft_strlen(s1);
	if ((!(s1)) || (!(set)))
		return (NULL);
	while (ft_strchr(set, s1[i]) != NULL)
		i++;
	while (ft_strchr(set, s1[lens1 - 1]) != NULL)
		lens1--;
	trimmed = ft_substr(s1, i, lens1 - i);
	return (trimmed);
}
/*
int	main()
{
	printf("%s stringa trimmata\n", ft_strtrim("lalblbl", "lb"));
	return (0);
}
*/
