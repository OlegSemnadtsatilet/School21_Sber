/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:53:00 by bmaya             #+#    #+#             */
/*   Updated: 2021/12/07 18:39:30 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lstack	*create_node(int number)
{
	t_lstack	*node;

	node = (t_lstack *)malloc(sizeof(t_lstack));
	node->number = number;
	node->order = -1;
	node->flag = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	addback_node(t_lstack **stack, t_lstack *node)
{
	t_lstack	*iter_node;

	if (*stack == NULL)
	{
		(*stack) = node;
		return ;
	}
	iter_node = *stack;
	while (iter_node->next != NULL)
		iter_node = iter_node->next;
	iter_node->next = node;
	node->prev = iter_node;
}

t_lstack	*take_last_node(t_lstack **stack)
{
	t_lstack	*iter_node;

	iter_node = *stack;
	while (iter_node->next != NULL)
		iter_node = iter_node->next;
	printf("Last node number: %d\n", iter_node->number);
	return (iter_node);
}

t_lstack	*take_first_node(t_lstack **stack)
{
	t_lstack	*iter_node;

	iter_node = *stack;
	printf("First node number: %d\n", iter_node->number);
	return (iter_node);
}

int	sort_check(t_lstack **stack)
{
	t_lstack	*iter_node;

	iter_node = *stack;
	while ((iter_node)->next != NULL)
	{
		if ((iter_node)->number < ((iter_node)->next)->number)
		{
			iter_node = (iter_node)->next;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}
