/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:00:33 by iborge-g          #+#    #+#             */
/*   Updated: 2025/05/26 12:23:02 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l1;

	l1 = (t_list *)malloc(sizeof(t_list));
	if (!l1)
		return (NULL);
	l1 -> content = content;
	l1 -> next = NULL;
	return (l1);
}
