/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:30:08 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/13 12:15:47 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_num(int n)
{
	int			count;
	long int	nb;

	count = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char *ft_itoa(int n)
{
	char		*c;
	int			i;
	long int	nb;
	int			len;

	nb = n;
	len = count_num(n);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (nb < 0)
	{
		c[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		c[0] = '0';
	i = len - 1;
	while (nb > 0)
	{
		c[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (c);
}
