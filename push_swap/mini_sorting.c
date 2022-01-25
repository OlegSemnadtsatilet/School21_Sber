/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:56:53 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/14 14:09:07 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three_numbers_a(t_storage *storage)
{
	t_lstack	*first;
	t_lstack	*second;
	t_lstack	*third;

	first = *storage->stack_a;
	second = first->next;
	third = second->next;
	if (first->number > second->number && first->number < third->number)
		sa(storage);
	else if (first->number > second->number && second->number > third->number)
	{
		sa(storage);
		rra(storage);
	}
	else if (first->number < second->number && first->number > third->number)
		rra(storage);
	else if (first->number < third->number && second->number > third->number)
	{
		rra(storage);
		sa(storage);
	}
	else if (third->number > second->number && first->number > third->number)
		ra(storage);
}

void	sorting_three_numbers_b(t_storage *storage)
{
	t_lstack	*first;
	t_lstack	*second;
	t_lstack	*third;

	first = *storage->stack_b;
	second = first->next;
	third = second->next;
	if (first->number > second->number && first->number < third->number)
		sb(storage);
	else if (first->number > second->number && second->number > third->number)
	{
		sb(storage);
		rrb(storage);
	}
	else if (first->number < second->number && first->number > third->number)
		rrb(storage);
	else if (first->number < third->number && second->number > third->number)
	{
		rrb(storage);
		sb(storage);
	}
	else if (third->number > second->number && first->number > third->number)
		rb(storage);
}

void	merging_two_stacks(t_storage *storage)
{
	while (*storage->stack_b)
	{
		if ((*storage->stack_b)->order < (*storage->stack_a)->order)
		{
			pa(storage);
			ra(storage);
		}
		else if ((*storage->stack_b)->order - (*storage->stack_a)->order == 1)
		{
			ra(storage);
			pa(storage);
		}
		else
			ra(storage);
	}
	while ((*storage->stack_a)->order != 0)
		ra(storage);
}

void	sorting_between_four_six(t_storage *storage)
{
	while (stack_size(storage->stack_a) > 3)
		pb(storage);
	if (sort_check(storage->stack_a) == 0)
		sorting_three_numbers_a(storage);
	if (stack_size(storage->stack_b) == 2)
	{
		if (sort_check(storage->stack_b) == 0)
			sb(storage);
	}
	else if (stack_size(storage->stack_b) == 3)
	{
		if (sort_check(storage->stack_b) == 0)
			sorting_three_numbers_b(storage);
	}
	merging_two_stacks(storage);
	return ;
}
