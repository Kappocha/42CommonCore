/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:00:00 by iborge-g          #+#    #+#             */
/*   Updated: 2025/09/10 17:01:25 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(Node **stacka)
{
	Node	*last;
	Node	*penultimate;

	if (*stacka == NULL || (*stacka)->next == NULL)
		return ;
	last = *stacka;
	while (last->next != NULL)
		last = last->next;
	penultimate = last->prev;
	if (penultimate)
		penultimate->next = NULL;
	last->next = *stacka;
	last->prev = NULL;
	(*stacka)->prev = last;
	*stacka = last;
}

void	rrb(Node **stackb)
{
	Node	*last;
	Node	*penultimate;

	if (*stackb == NULL || (*stackb)->next == NULL)
		return ;
	last = *stackb;
	while (last->next != NULL)
		last = last->next;
	penultimate = last->prev;
	if (penultimate != NULL)
		penultimate->next = NULL;
	last->next = *stackb;
	last->prev = NULL;
	(*stackb)->prev = last;
	*stackb = last;
}

void	rrr(Node **stacka, Node **stackb)
{
	rra(stacka);
	rrb(stackb);
}
