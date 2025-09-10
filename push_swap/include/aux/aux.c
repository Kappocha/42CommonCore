/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:53:08 by iborge-g          #+#    #+#             */
/*   Updated: 2025/09/01 16:57:06 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"

int	absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	stack_size(Node *stack)
{
	Node	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_best_pos(Node *tmp, int target)
{
	int	best_pos;
	int	best_val;
	int	i;

	i = 0;
	best_pos = 0;
	best_val = -2147483648;
	while (tmp)
	{
		if (tmp->num < target && tmp->num > best_val)
		{
			best_val = tmp->num;
			best_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (best_pos);
}

int	find_insert_position(Node *stack, int target)
{
	int		i;
	Node	*tmp;
	Node	*min_node;
	int		min_val;
	int		best_pos;

	i = 0;
	min_node = stack;
	tmp = stack;
	if (!stack)
		return (0);
	min_val = stack->num;
	tmp = stack;
	while (tmp)
	{
		if (tmp->num < min_val)
		{
			min_val = tmp->num;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	if (target < min_val)
	{
		i = 0;
		tmp = stack;
		while (tmp != min_node)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	tmp = stack;
	best_pos = find_best_pos(tmp, target);
	return ((best_pos + 1) % stack_size(stack));
}
