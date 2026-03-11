/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:50:56 by flavides          #+#    #+#             */
/*   Updated: 2026/01/28 16:46:05 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*c: The character to output.
fd: The file descriptor on which to write.

Outputs the character ’c’ to the specified file
descriptor.*/
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
