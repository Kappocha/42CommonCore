/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:10:27 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/12 11:51:55 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	instart(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (s1[i] != '\0')
	{
		found = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			return (i);
		i++;
	}
	return (i);
}

int	inend(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = ft_strlen(s1) - 1;
	while (s1[i] >= 0)
	{
		found = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*sfin;
	int		start;
	int		end;

	i = 0;
	start = instart(s1, set);
	end = inend(s1, set);
	if (start > end)
		return (ft_strdup(""));
	sfin = malloc(end - start + 2);
	if (!sfin)
		return (NULL);
	while (start <= end)
		sfin[i++] = s1[start++];
	sfin[i] = '\0';
	return (sfin);
}
