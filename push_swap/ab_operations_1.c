/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_operations1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:55:21 by bmaya             #+#    #+#             */
/*   Updated: 2021/12/13 16:57:36 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_storage *storage)
{
	swap(storage->stack_a);
	storage->steps++;
	write(1, "sa\n", 3);
}

void	sb(t_storage *storage)
{
	swap(storage->stack_b);
	storage->steps++;
	write(1, "sb\n", 3);
}

void	ss(t_storage *storage)
{
	swap(storage->stack_a);
	swap(storage->stack_b);
	storage->steps++;
	write(1, "ss\n", 3);
}

void	pa(t_storage *storage)
{
	push(storage->stack_b, storage->stack_a);
	storage->steps++;
	write(1, "pa\n", 3);
}

void	pb(t_storage *storage)
{
	push(storage->stack_a, storage->stack_b);
	storage->steps++;
	write(1, "pb\n", 3);
}
