/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:34:24 by flavides          #+#    #+#             */
/*   Updated: 2026/02/12 15:15:59 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 Allocates memory (using malloc(3)) and returns
a new node. The ’content’ member variable is
initialized with the given parameter ’content’.
The variable ’next’ is initialized to NULL.

 NON  PERDERE LA TESTA*/
t_list	*ft_lstnew(void *content)
{
	t_list	*linknew;

	linknew = ft_calloc(1, sizeof(t_list));
	linknew->content = content;
	linknew->next = NULL;
	return (linknew);
}
