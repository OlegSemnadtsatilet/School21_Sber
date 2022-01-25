/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:37:01 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/19 18:09:04 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	crra(t_storage *storage)
{
	reverse_rotate(storage->stack_a);
	storage->steps++;
}

void	crrb(t_storage *storage)
{
	reverse_rotate(storage->stack_b);
	storage->steps++;
}

void	crrr(t_storage *storage)
{
	reverse_rotate(storage->stack_a);
	reverse_rotate(storage->stack_b);
	storage->steps++;
}
