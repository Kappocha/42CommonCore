/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:06:54 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/14 16:32:23 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (ptr[i] == ' ' || (ptr[i] >= 9 && ptr[i] <= 13))
	{
		i += 1;
	}
	if (ptr[i] == '-')
	{
		sign = -1;
		i += 1;
	}
	else if (ptr[i] == '+')
		i += 1;
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		nb = nb * 10 + (ptr[i] - '0');
		i += 1;
	}
	return (nb * sign);
}
