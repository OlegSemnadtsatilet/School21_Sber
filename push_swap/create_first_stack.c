/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_first_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:20:30 by bmaya             #+#    #+#             */
/*   Updated: 2021/12/07 18:39:19 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_lstack **stack)
{
	int			size;
	t_lstack	*iter_node;

	iter_node = *stack;
	size = 0;
	while ((iter_node)->next)
	{
		iter_node = (iter_node)->next;
		size++;
	}
	return (size);
}

static void	print_stack(t_lstack **stack)
{
	t_lstack	*iter_node;

	iter_node = *stack;
	while (iter_node != NULL)
	{
		printf("Number: %d, Order: %d\n", iter_node->number, iter_node->order);
		iter_node = iter_node->next;
	}
}

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

int	create_first_lstack(t_storage *storage, int argc, char **argv)
{
	int			counter;

	counter = 0;
	while (++counter < argc)
		addback_node(storage->stack_a, create_node(ft_atoi(argv[counter])));
	return (0);
}

int	main(int argc, char **argv)
{
	t_storage	*storage;
	t_lstack	*stack_a;
	t_lstack	*stack_b;

	storage = malloc(sizeof(t_storage));
	storage->stack_a = &stack_a;
	storage->stack_b = &stack_b;
	create_first_lstack(storage, argc, argv);
	take_first_node(storage->stack_a);
	take_last_node(storage->stack_a);
	printf("Stack is sorted? %d\n", sort_check(storage->stack_a));
	printf("Stack size %d\n", stack_size(storage->stack_a));
	make_orders(storage->stack_a);
	print_stack(storage->stack_a);
	return (0);
}
