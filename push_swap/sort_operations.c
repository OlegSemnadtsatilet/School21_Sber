/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:48:11 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/25 13:37:37 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lstack **stack)
{
	t_lstack	*first_node;
	t_lstack	*second_node;

	first_node = *stack;
	if (!stack || !*stack || !first_node->next)
		return ;
	second_node = first_node->next;
	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->next = first_node;
	second_node->prev = NULL;
	first_node->prev = second_node;
	*stack = second_node;
}

void	push(t_lstack **from_stack, t_lstack **to_stack)
{
	t_lstack	*iter_node;

	iter_node = *from_stack;
	if (iter_node->next)
	{
		*from_stack = iter_node->next;
		(*from_stack)->prev = NULL;
		if (*to_stack)
		{
			iter_node->next = *to_stack;
			iter_node->next->prev = iter_node;
		}
		else
			iter_node->next = NULL;
		*to_stack = iter_node;
	}
	else
	{
		iter_node->next = *to_stack;
		*to_stack = iter_node;
		*from_stack = NULL;
	}
}

void	rotate(t_lstack **stack)
{
	t_lstack	*first_node;
	t_lstack	*last_node;

	if (!stack || !*stack)
		return ;
	first_node = *stack;
	if (first_node->next)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last_node = take_last_node(stack);
		first_node->next = NULL;
		last_node->next = first_node;
		first_node->prev = last_node;
	}
}

void	reverse_rotate(t_lstack **stack)
{
	t_lstack	*last_node;
	t_lstack	*first_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = take_last_node(stack);
	if (last_node)
	{
		(last_node->prev)->next = NULL;
		last_node->next = first_node;
		first_node->prev = last_node;
		*stack = last_node;
		last_node->prev = NULL;
	}
}
