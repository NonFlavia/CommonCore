/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:13:00 by flavides          #+#    #+#             */
/*   Updated: 2025/12/20 19:38:04 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DAL MAN: trova un char in una stringa
La funzione strchr() ritorna un puntatore
che punta alla prima occorrenze
di un char nella str. */

#include "libft.h"
//itera, si ferma se ci sta occ del char c, se no occ. ret. NULL
char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	cielo;

	i = 0;
	cielo = (unsigned char) c;
	while (s[i] != '\0' && s[i] != cielo)
		i++;
	if (!s || s[i] != cielo)
		return (NULL);
	return ((char *)&s[i]);
}
/*
int	main()
{
	char flavi[5] = "flavi";
	printf("il carattere trovato e' %s\n", ft_strchr(flavi,'a'));

}
*/
