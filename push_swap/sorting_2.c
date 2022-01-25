/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:37:08 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/14 14:11:04 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_flags(t_storage *storage)
{
	t_lstack	*iter_node;

	iter_node = *storage->stack_b;
	while (iter_node)
	{
		iter_node->flag = absolute(steps_to_top_b(storage, iter_node)) \
		+ absolute(steps_to_closest_a(storage, iter_node)) + 1;
		iter_node = iter_node->next;
	}
}

void	closest_a_to_top(t_storage *storage, int a_steps)
{
	while (a_steps > 0)
	{
		ra(storage);
		a_steps--;
	}
	while (a_steps < 0)
	{
		rra(storage);
		a_steps++;
	}
}

void	min_flag_b_to_top(t_storage *storage, int b_steps)
{
	while (b_steps > 0)
	{
		rb(storage);
		b_steps--;
	}
	while (b_steps < 0)
	{
		rrb(storage);
		b_steps++;
	}	
}

void	put_nodes_to_top(t_storage *storage, int a_steps, int b_steps)
{
	while (a_steps > 0 && b_steps > 0)
	{
		rr(storage);
		a_steps--;
		b_steps--;
	}
	while (a_steps < 0 && b_steps < 0)
	{
		rrr(storage);
		a_steps++;
		b_steps++;
	}
	closest_a_to_top(storage, a_steps);
	min_flag_b_to_top(storage, b_steps);
}

void	push_min_flag(t_storage *storage)
{
	int			find_min_flag;
	t_lstack	*iter_node;
	t_lstack	*mem_node;

	find_min_flag = storage->max_order;
	iter_node = *storage->stack_b;
	while (iter_node)
	{
		if (iter_node->flag <= find_min_flag)
		{
			find_min_flag = iter_node->flag;
			mem_node = iter_node;
		}
		iter_node = iter_node->next;
	}
	put_nodes_to_top(storage, \
	steps_to_closest_a(storage, mem_node), steps_to_top_b(storage, mem_node));
	pa(storage);
}
