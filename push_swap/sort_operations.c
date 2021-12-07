/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:48:11 by bmaya             #+#    #+#             */
/*   Updated: 2021/12/04 13:39:17 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(t_lstack **stack)
{
	t_lstack	*iter_node;

	if (!*stack || !(*stack->next))
		return ;
	iter_node = *stack->next;
	*stack->next = iter_node->next;
	iter_node->next = *stack;
	iter_node->prev = NULL;
	*stack->prev = iter_node;
}

void	push(t_lstack **from_stack, t_lstack **to_stack)
{
	t_lstack	*temp_node;

	if (!*from_stack)
		return ;
	temp_node = *from_stack;
	temp_node->next = *to_stack;
	*to_stack->prev = temp_node;
	*from_stack = *from_stack->next;
	*from_stack->prev = NULL;
}

void	rotate(t_lstack **stack)
{
	t_lstack	*first_node;

	first_node = *stack;
	*stack = *stack->next;
	*stack->prev = NULL;
	while (*stack->next)
		*stack = *stack->next;
	*stack->next = first_node;
}

t_lstack	take_last_node(t_lstack **stack)
{
	while (*stack->next)
		*stack = *stack->next;
	return (*stack);
}

void	reverse_rotate(t_lstack **stack)
{
	t_lstack	*last_node;

	last_node = take_last_node(stack);
	last_node->next = *stack;
	*stack->prev = last_node;
	while (*stack->next)
		*stack = *stack->next;
	*stack = *stack->prev;
	*stack->next = NULL;
}
