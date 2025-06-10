/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:19:40 by iborge-g          #+#    #+#             */
/*   Updated: 2025/06/10 11:43:48 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	formatto(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putuns(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'x')
		return (ft_printhexl(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_printhexu(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	return (0);
}

int	ft_printf(char const *formato, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	if (!formato)
	    return (0);
	va_start(args, formato);
	while (formato[i])
	{
		if (formato[i] == '%' && formato[i + 1])
		{
			total += formatto(formato[i + 1], args);
			i += 2;
		}
		else
		{
			total += ft_putchar(formato[i]);
			i++;
		}
	}
	va_end(args);
	return (total);
}
