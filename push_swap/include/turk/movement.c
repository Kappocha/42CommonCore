/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:06:24 by iborge-g          #+#    #+#             */
/*   Updated: 2025/09/10 17:10:44 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int calc_move_a(Node *stacka, int target)
{
	int size;
	int pos;

	size = stack_size(stacka);
	pos = find_insert_position(stacka, target);
	if (pos <= size / 2)
		return pos;
	else
		return pos - size;
}

int calc_move_b(Node *stackb, int pos)
{
	int size = stack_size(stackb);
	if (pos <= size / 2)
		return pos;
	else
		return pos - size;
}

t_move calc_best_move(Node *stacka, Node *stackb)
{
	t_move best;
	int i;
	Node *tmpb;
	int max_moves;

	tmpb = stackb;
	best.total = 2147483647;
	i = 0;
	while (tmpb) 
	{
		t_move actual;
		actual.index_b = i;
		actual.moves_b = calc_move_b(stackb, i);
		actual.moves_a = calc_move_a(stacka, tmpb->num);
		actual.total = absolute(actual.moves_a) + absolute(actual.moves_b);
		if ((actual.moves_a > 0 && actual.moves_b > 0) || 
			(actual.moves_a < 0 && actual.moves_b < 0))
		{
			actual.total = max_moves;
			if (absolute(actual.moves_a) > absolute(actual.moves_b))
				max_moves = absolute(actual.moves_a);
			else
				max_moves = absolute(actual.moves_b);
		}
		if (actual.total < best.total)
			best = actual;
		tmpb = tmpb->next;
		i++;
	}
	return (best);
}
