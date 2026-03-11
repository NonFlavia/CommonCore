/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:29:32 by flavides          #+#    #+#             */
/*   Updated: 2026/02/06 18:15:06 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* lst: The address of a pointer to the first node of
a list.
new: The address of a pointer to the node to be
added.
Adds the node ’new’ at the beginning of the list
NON PERDERE LA TESTA
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (! new || ! lst)
		return ;
	new->next = *lst;
	*lst = new;
}
