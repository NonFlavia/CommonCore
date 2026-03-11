/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flavides <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:24:22 by flavides          #+#    #+#             */
/*   Updated: 2025/12/20 18:17:38 by flavides         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*stringcp;
	int		len;

	len = ft_strlen(string);
	stringcp = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(stringcp, string, len + 1);
	return (stringcp);
}
/*

int	main()
{

	int 	i = 0;
	char dacopiare[107] = "gianni ciao"; 
// qua c'e' qualcosa che non va quando modifico il buffer, ho duvbbbiiii
	char *copiato =  ft_strdup(dacopiare);
	while (copiato[i] != '\0')
	{
		write(1, &copiato[i], 1);
		i++;
	}
	if (copiato[i] == '\0')
		write (1, " terminatore qui\n", 23);
	return(0);

} */
