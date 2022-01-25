/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:20:30 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/20 15:34:45 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sorting(t_storage *storage, int argc)
{
	if (argc == 3)
		if (sort_check(storage->stack_a) == 0)
			sa(storage);
	if (argc == 4)
		sorting_three_numbers_a(storage);
	else if (argc > 4)
		sorting_between_four_six(storage);
}

void	sorting(t_storage *storage)
{
	push_mid_node(storage);
	push_all_to_b(storage);
	while (*storage->stack_b)
	{
		give_flags(storage);
		push_min_flag(storage);
	}
	last_rotate(storage);
}

static void	free_all(t_storage *storage)
{
	while ((*storage->stack_a)->next)
	{
		(*storage->stack_a) = (*storage->stack_a)->next;
		free((*storage->stack_a)->prev);
	}
	free(*storage->stack_a);
	free(storage);
}

int	main(int argc, char **argv)
{
	t_storage	*storage;
	t_lstack	*stack_a;
	t_lstack	*stack_b;

	if (argc < 2)
		exit (1);
	storage = malloc(sizeof(t_storage));
	if (!storage)
		exit (1);
	storage->stack_a = &stack_a;
	storage->stack_b = &stack_b;
	if (create_first_lstack(storage, argc, argv) == 1 \
	|| error_out_check(argv, storage->stack_a) == 1 \
	|| sort_check(storage->stack_a) == 1)
		exit (1);
	make_orders(storage->stack_a);
	if (argc <= 7)
		mini_sorting(storage, argc);
	else
		sorting(storage);
	free_all(storage);
	return (0);
}
