/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:52:30 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/19 10:10:04 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

int	word_size(char const *s, char c, int ind)
{
	int	size;

	size = 0;
	while (s[ind] != c && s[ind] != '\0')
	{
		size++;
		ind++;
	}
	return (size);
}

int	fill_array(char const *s, char c, char **arr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			arr[j] = malloc((word_size(s, c, i) + 1) * sizeof(char));
			if (!arr[j])
				return (0);
			k = 0;
			while (s[i] != c && s[i] != '\0')
				arr[j][k++] = s[i++];
			arr[j][k] = '\0';
			j++;
		}
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**arr;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	arr = malloc((count + 1) * sizeof (char *));
	if (!arr)
		return (NULL);
	if (!fill_array(s, c, arr))
		return (NULL);
	return (arr);
}
