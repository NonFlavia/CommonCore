/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:48:20 by flavides          #+#    #+#             */
/*   Updated: 2026/02/11 18:19:26 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
ft_lstsize
Prototype int ft_lstsize(t_list *lst);
Files to Submit -
Parameters lst: The beginning of the list.
Return Value The length of the list
External Function None
Description Counts the number of nodes in the list.
*/
int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	if (! lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
