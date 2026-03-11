/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:47:53 by flavides          #+#    #+#             */
/*   Updated: 2026/02/09 16:53:31 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*lst: The node to free.
del: The address of the function used to delete
the content.
free
Takes a node as parameter and frees its content
using the function ’del’. Free the node itself but
does NOT free the next node.

prende un nodo come parametro e frea il suo contenuto usando la fun del
frea il nodo ma non cio che c'e' dopo
NON PERDERE LA TESTA
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (! lst || ! del)
		return ;
	del(lst->content);
	free(lst);
}
