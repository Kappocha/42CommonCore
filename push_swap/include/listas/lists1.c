/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:54:09 by iborge-g          #+#    #+#             */
/*   Updated: 2025/09/10 16:58:16 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(Node **stacka)
{
	int	tmp;

	if (stacka && (*stacka)->next)
	{
		tmp = (*stacka)->num;
		(*stacka)->num = (*stacka)->next->num;
		(*stacka)->next->num = tmp;
	}
}

void	sb(Node **stackb)
{
	int	tmp;

	if (stackb && (*stackb)->next)
	{
		tmp = (*stackb)->num;
		(*stackb)->num = (*stackb)->next->num;
		(*stackb)->next->num = tmp;
	}
}

void	ss(Node **stacka, Node **stackb)
{
	int	tmp;

	if (stacka && (*stacka)->next)
	{
		tmp = (*stacka)->num;
		(*stacka)->num = (*stacka)->next->num;
		(*stacka)->next->num = tmp;
	}
	if (stackb && (*stackb)->next)
	{
		tmp = (*stackb)->num;
		(*stackb)->num = (*stackb)->next->num;
		(*stackb)->next->num = tmp;
	}
}

void	pa(Node **stacka, Node **stackb)
{
	Node	*tmp;

	if (*stackb == NULL)
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	if (*stackb)
		(*stackb)->prev = NULL;
	tmp->next = *stacka;
	if (*stacka)
		(*stacka)->prev = tmp;
	tmp->prev = NULL;
	*stacka = tmp;
}

void	pb(Node **stacka, Node **stackb)
{
	Node	*tmp;

	if (*stacka == NULL)
		return ;
	tmp = *stacka;
	*stacka = (*stacka)->next;
	if (*stacka)
		(*stacka)->prev = NULL;
	tmp->next = *stackb;
	if (*stackb)
		(*stackb)->prev = tmp;
	tmp->prev = NULL;
	*stackb = tmp;
}
