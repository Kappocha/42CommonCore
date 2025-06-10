/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:19:41 by iborge-g          #+#    #+#             */
/*   Updated: 2025/06/02 11:40:00 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexl(unsigned int n)
{
	char	*basel;
	int		i;

	basel = "0123456789abcdef";
	i = 0;
	if (n >= 16)
		i += ft_printhexl(n / 16);
	i += ft_putchar(basel[n % 16]);
	return (i);
}

int	ft_printhexu(unsigned int n)
{
	char	*baseu;
	int		i;

	baseu = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
		i += ft_printhexu(n / 16);
	i += ft_putchar(baseu[n % 16]);
	return (i);
}

int	ft_putptr(void *n)
{
	unsigned long	dir;
	int				i;

	dir = (unsigned long)n;
	i = 0;
	i += ft_putstr("0x");
	i += ft_printhexl(dir);
	return (i);
}
