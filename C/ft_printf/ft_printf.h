/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:58:34 by flavides          #+#    #+#             */
/*   Updated: 2026/03/03 16:59:03 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

//ft_printf.c fun base da cui si dirama tutto
int	istheend(va_list ap, const char *str);
int	ft_printf(const char *str, ...);
//ft_handlecases.c gestisce i tipi e ritorna char stamp
int	ft_pointers(va_list *ap);
int	ft_exapointers(char c, va_list *ap);
int	ft_complicatednum(char c, va_list *ap);
int	ft_handlecases(char type, va_list *ap);
//ft_utility.c funzioni che lavorano per rendere stamp
int	ft_putstr(char *toprint);
int	ft_itoaprint(long nb);
int	ft_itoaexa(unsigned int nb, const char *exacase);
int	ft_itoapointers(unsigned long nb, const char *exacase);
#endif
