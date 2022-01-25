/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:59:07 by bmaya             #+#    #+#             */
/*   Updated: 2021/12/13 16:59:27 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_storage *storage)
{
	rotate(storage->stack_a);
	storage->steps++;
	write(1, "ra\n", 3);
}

void	rb(t_storage *storage)
{
	rotate(storage->stack_b);
	storage->steps++;
	write(1, "rb\n", 3);
}

void	rr(t_storage *storage)
{
	rotate(storage->stack_a);
	rotate(storage->stack_b);
	storage->steps++;
	write(1, "rr\n", 3);
}
