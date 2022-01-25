/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:15:49 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/14 14:11:29 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_mid_node(t_storage *storage)
{
	int			position;
	int			ra_rra_flag;
	t_lstack	*iter_node;

	position = 0;
	ra_rra_flag = 0;
	iter_node = *storage->stack_a;
	while (iter_node->order != storage->mid_order)
	{
		position++;
		iter_node = iter_node->next;
	}
	if (position <= stack_size(storage->stack_a) / 2)
		ra_rra_flag = 1;
	while ((*storage->stack_a)->order != storage->mid_order)
	{
		if (ra_rra_flag == 1)
			ra(storage);
		else
			rra(storage);
	}
	pb(storage);
}

void	push_all_to_b(t_storage *storage)
{
	while (*storage->stack_a)
	{
		if ((*storage->stack_a)->order == 0 \
		|| (*storage->stack_a)->order == storage->max_order)
		{
			if (stack_size(storage->stack_a) == 2)
				break ;
			ra(storage);
		}
		else
		{
			if ((*storage->stack_a)->order < storage->mid_order)
				pb(storage);
			else if ((*storage->stack_a)->order > storage->mid_order)
			{
				pb(storage);
				rb(storage);
			}
		}
	}
}

int	steps_to_top_b(t_storage *storage, t_lstack *node)
{
	t_lstack	*iter_node;
	int			steps;

	steps = 0;
	iter_node = *storage->stack_b;
	while (iter_node->order != node->order)
	{
		iter_node = iter_node->next;
		steps++;
	}
	if (steps <= stack_size(storage->stack_b) / 2)
		return (steps);
	else
		return (steps - stack_size(storage->stack_b));
}

int	steps_to_closest_a(t_storage *storage, t_lstack *node)
{
	int			closest;
	int			counter;
	int			steps;
	t_lstack	*iter_node;

	steps = 0;
	counter = 0;
	closest = storage->max_order;
	iter_node = *storage->stack_a;
	while (iter_node)
	{
		if ((iter_node->order <= closest) && (iter_node->order > node->order))
		{
			closest = iter_node->order;
			steps = counter;
		}
		iter_node = iter_node->next;
		counter++;
	}
	if (steps <= stack_size(storage->stack_a) / 2)
		return (steps);
	else
		return (steps - stack_size(storage->stack_a));
}

int	absolute(int value)
{
	if (value < 0)
		return (value * (-1));
	else
		return (value);
}
