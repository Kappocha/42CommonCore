/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:58:53 by iborge-g          #+#    #+#             */
/*   Updated: 2025/06/18 18:00:54 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*empty_string(void)
{
	char	*sub;

	sub = ((char *)malloc(1));
	if (!sub)
		return (NULL);
	sub[0] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	slen;

	i = 0;
	slen = 0;
	if (!s)
		return (NULL);
	while (s[slen])
		slen++;
	if (start >= slen)
		return (empty_string());
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

char	*ft_strchr(char const *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		slen;
	char	*sfin;

	i = 0;
	j = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	slen = ft_strlen(s1) + ft_strlen(s2);
	sfin = malloc(slen + 1);
	if (!sfin)
		return (NULL);
	while (s1[i])
	{
		sfin[i] = s1[i];
		i++;
	}
	while (s2[j])
		sfin[i++] = s2[j++];
	sfin[i] = '\0';
	return (sfin);
}
