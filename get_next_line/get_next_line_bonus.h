/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:03:45 by flavides          #+#    #+#             */
/*   Updated: 2026/04/10 17:03:48 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
// get_next_line_utils_bunus
char	*ft_strtorest(char *str, char *rest, int *i);
int		ft_getlen(char *str);
int		ft_lennewline(char *str);
int		ft_isanewline(char *str);
char	*ft_getstrjoin(char *str1, char *str2);
// get_next_line_bonus
char	*ft_getrest(char *str);
char	*ft_readandsave(int fd, char *str);
char	*ft_getline(char *str);
char	*get_next_line(int fd);
#endif
