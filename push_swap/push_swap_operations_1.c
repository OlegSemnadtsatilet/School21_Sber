/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:56:49 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/19 18:32:32 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_orders(t_lstack **stack)
{
	int			position_order;
	int			find_min_num;
	t_lstack	*iter_node;
	t_lstack	*saved_node;

	position_order = 0;
	while (position_order < stack_size(stack))
	{
		iter_node = *stack;
		find_min_num = 2147483647;
		while (iter_node)
		{
			if (iter_node->order == -1 && iter_node->number < find_min_num)
			{
				saved_node = iter_node;
				find_min_num = iter_node->number;
			}
			iter_node = iter_node->next;
		}
		saved_node->order = position_order;
		position_order++;
	}
	return (0);
}

void	last_rotate_cicles(t_storage *storage, int steps)
{
	if (steps <= stack_size(storage->stack_a) / 2)
	{
		while (steps)
		{
			ra(storage);
			steps--;
		}
	}
	else
	{
		steps = stack_size(storage->stack_a) - steps;
		while (steps)
		{
			rra(storage);
			steps--;
		}
	}
}

void	last_rotate(t_storage *storage)
{
	t_lstack	*iter_node;
	int			steps;

	steps = 0;
	iter_node = *storage->stack_a;
	while (iter_node->order != 0)
	{
		steps++;
		iter_node = iter_node->next;
	}
	last_rotate_cicles(storage, steps);
}
