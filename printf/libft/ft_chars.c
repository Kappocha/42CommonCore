/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:49:48 by iborge-g          #+#    #+#             */
/*   Updated: 2025/06/10 11:44:48 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (write(1, "(null)", 6));
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long int	nb;
	int			i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10)
		i += ft_putchar(nb + '0');
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putchar(nb % 10 + '0');
	}
	return (i);
}

int	ft_putuns(unsigned int n)
{
	unsigned long int	nb;
	int			i;

	nb = n;
	i = 0;
	if (nb < 0)
		nb = -nb;
	if (nb < 10)
		i += ft_putchar(nb + '0');
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putchar(nb % 10 + '0');
	}
	return (i);
}
