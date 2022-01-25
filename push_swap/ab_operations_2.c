/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:37:01 by bmaya             #+#    #+#             */
/*   Updated: 2021/12/13 16:59:00 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_storage *storage)
{
	reverse_rotate(storage->stack_a);
	storage->steps++;
	write(1, "rra\n", 4);
}

void	rrb(t_storage *storage)
{
	reverse_rotate(storage->stack_b);
	storage->steps++;
	write(1, "rrb\n", 4);
}

void	rrr(t_storage *storage)
{
	reverse_rotate(storage->stack_a);
	reverse_rotate(storage->stack_b);
	storage->steps++;
	write(1, "rrr\n", 4);
}
