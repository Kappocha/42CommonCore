/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:09:15 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/15 19:02:03 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*caso(int start, int slen)
{
	char *sub;

	if (start >= slen)
	{
        sub = ((char *)malloc(1));
        if (!sub)
            return (NULL);
        sub[0] = '\0';
        return (sub);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	slen;

	i = 0;
	slen = 0;
	while (s[slen])
		slen++;
	printf("La longitud de la palabra es %zu\n", slen);
	sub = caso(start, slen);
	printf("Sub es %s\n", sub);
	if (!sub)
		return (sub);
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
