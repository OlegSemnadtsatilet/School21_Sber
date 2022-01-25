/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:12:11 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/19 18:08:55 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	csa(t_storage *storage)
{
	swap(storage->stack_a);
	storage->steps++;
}

void	csb(t_storage *storage)
{
	swap(storage->stack_b);
	storage->steps++;
}

void	css(t_storage *storage)
{
	swap(storage->stack_a);
	swap(storage->stack_b);
	storage->steps++;
}

void	cpa(t_storage *storage)
{
	push(storage->stack_b, storage->stack_a);
	storage->steps++;
}

void	cpb(t_storage *storage)
{
	push(storage->stack_a, storage->stack_b);
	storage->steps++;
}
