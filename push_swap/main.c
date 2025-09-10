/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:16:39 by iborge-g          #+#    #+#             */
/*   Updated: 2025/09/01 16:52:34 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	Node	*stack_a;
	Node	*stack_b;
	int		contador;

	contador = 0;
	stack_b = NULL;
	stack_a = start_nodes(argc, argv);
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (is_sorted(stack_a))
	{
		free_list(stack_a);
		return (0);
	}
	start_stack(&stack_a, &stack_b, &contador);
	sort_three(&stack_a, &contador);
	move_all_b_to_a(&stack_a, &stack_b, &contador);
	final_rotate_to_min(&stack_a, &contador);
	free_list(stack_a);
	return (0);
}
