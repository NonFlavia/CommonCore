/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:46:34 by flavides          #+#    #+#             */
/*   Updated: 2026/01/28 17:01:36 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*s: The string to output.
fd: The file descriptor on which to write.

Outputs the string ’s’ to the specified file
descriptor.*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
