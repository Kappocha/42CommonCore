/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:02:08 by iborge-g          #+#    #+#             */
/*   Updated: 2025/09/10 17:05:57 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_list(Node *head)
{
	Node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	no_dup(int argc, char **argv)
{
	int	i;
	int	j;
	int	tmp;
	int	cmp;

	i = 1;
	while (i < argc - 1)
	{
		tmp = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			cmp = ft_atoi(argv[j]);
			if (tmp == cmp)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

Node	*start_nodes(int argc, char **argv)
{
	Node	*head;
	Node	*tail;
	Node	*new;
	int		i;

	head = NULL;
	tail = NULL;
	i = 1;
	if (!no_dup(argc, argv))
		return (NULL);
	while (i < argc)
	{
		new = malloc(sizeof(Node));
		if (!new)
		{
			ft_printf("Error\n");
			free_list(head);
			return (NULL);
		}
		new->num = ft_atoi(argv[i]);
		new->next = NULL;
		new->prev = tail;
		if (tail)
			tail->next = new;
		else
			head = new;
		tail = new;
		i++;
	}
	return (head);
}
