/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:43:04 by flavides          #+#    #+#             */
/*   Updated: 2026/02/11 17:00:29 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
lst: The address of a pointer to a node.
f: The address of the function to apply to each
node’s content.
terates through the list ’lst’ and applies the
function ’f’ to the content of each node
NON PERDERE LA TESTA!*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (! lst || ! f)
		return ;
	while (lst)
	{
		(f(lst->content));
		lst = lst->next;
	}
}
