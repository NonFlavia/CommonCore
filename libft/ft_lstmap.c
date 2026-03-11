/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:00:53 by flavides          #+#    #+#             */
/*   Updated: 2026/02/11 17:10:17 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
lst: The address of a pointer to a node.
f: The address of the function applied to each
node’s content. -> posso usare ft_lstiter
del: The address of the function used to delete a
node’s content if needed.

The new list.
NULL if the allocation fails.

malloc, free

Iterates through the list ’lst’, applies the
function ’f’ to each node’s content, and creates
a new list resulting of the successive applications
of the function ’f’. The ’del’ function is used to
delete the content of a node if needed.

*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*head;

	if (! lst || ! f || ! del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		newlist = ft_lstnew((f(lst->content)));
		if (! newlist)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, newlist);
		lst = lst->next;
	}
	return (head);
}
