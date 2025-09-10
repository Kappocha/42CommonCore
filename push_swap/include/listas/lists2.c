/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:58:27 by iborge-g          #+#    #+#             */
/*   Updated: 2025/09/10 16:59:51 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(Node **stacka)
{
	Node	*first;
	Node	*last;

	if (*stacka == NULL || (*stacka)->next == NULL)
		return ;
	first = *stacka;
	*stacka = first->next;
	(*stacka)->prev = NULL;
	last = *stacka;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rb(Node **stackb)
{
	Node	*first;
	Node	*last;

	if (*stackb == NULL || (*stackb)->next == NULL)
		return ;
	first = *stackb;
	*stackb = first->next;
	(*stackb)->prev = NULL;
	last = *stackb;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rr(Node **stacka, Node **stackb)
{
	ra(stacka);
	rb(stackb);
}
