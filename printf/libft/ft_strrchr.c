/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:23:03 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/13 13:01:58 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			last = (char *) &s[i];
		i++;
	}
	if (c == '\0')
		return ((char *) &s[i]);
	return (last);
}
