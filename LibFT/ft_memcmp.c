/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:40:53 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/06 16:47:17 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp (const void *s1, const void *s2, size_t n)
{
	size_t i;
	const unsigned char *ptr1;
	const unsigned char *ptr2;

	i = 0;
	ptr1 = (const unsigned char *) s1;
	ptr2 = (const unsigned char *) s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
		{
			return (ptr1[i] - ptr2[i]);
		}
		i++;
	}
	return (0);
}
