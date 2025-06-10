/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:54:07 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/09 18:09:58 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*sfin;
	int		slen;

	i = 0;
	j = 0;
	slen = ft_strlen(s1) + ft_strlen(s2);
	sfin = malloc(slen + 1);
	if (!sfin)
		return (NULL);
	while (s1[i] != '\0')
	{
		sfin[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		sfin[i] = s2[j];
		i++;
		j++;
	}
	sfin[i] = '\0';
	return (sfin);
}
