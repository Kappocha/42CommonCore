/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:38:35 by iborge-g          #+#    #+#             */
/*   Updated: 2025/09/10 16:53:26 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_sorted(Node *stacka)
{
	while (stacka && stacka->next)
	{
		if (stacka->num > stacka->next->num)
			return (0);
		stacka = stacka->next;
	}
	return (1);
}

int	find_min_position(Node *stacka)
{
	int		pos;
	int		min_pos;
	int		min;
	Node	*curr;

	curr = stacka;
	pos = 0;
	min_pos = 0;
	min = stacka->num;
	while (curr)
	{
		if (curr->num < min)
		{
			min = curr->num;
			min_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}

void	final_rotate_to_min(Node **stacka, int *counter)
{
	int	min_pos;
	int	size;
	int	i;

	min_pos = find_min_position(*stacka);
	size = stack_size(*stacka);
	if (min_pos <= size / 2)
	{
		i = 0;
		while (i < min_pos)
		{
			ra(stacka);
			(*counter)++;
			ft_printf("ra\n");
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - min_pos)
		{
			rra(stacka);
			(*counter)++;
			ft_printf("rra\n");
			i++;
		}
	}
}
