/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:47:28 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/13 12:58:10 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len && hs[i])
	{
		j = 0;
		while (hs[i + j] == nd[j] && nd[j] && (i + j) < len)
			j++;
		if (nd[j] == '\0')
			return ((char *) &hs[i]);
		i++;
	}
	return (NULL);
}
