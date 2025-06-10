/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:12:30 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/26 12:42:36 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int test_chars[] = {'a', 'z', 'A', 'Z', 'm', 'M', '0', '!', 128, -1};
    int i = 0;
    int result_ft, result_std;

    while (i < 10)
    {
        result_ft = ft_toupper(test_chars[i]);
        result_std = toupper(test_chars[i]);
        printf("Input: '%c' (%d) | ft_toupper: '%c' (%d) | toupper: '%c' (%d)\n",
            test_chars[i], test_chars[i],
            result_ft, result_ft,
            result_std, result_std);
        i++;
    }

    return 0;
}*/
