/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:59:07 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/19 18:09:08 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	cra(t_storage *storage)
{
	rotate(storage->stack_a);
	storage->steps++;
}

void	crb(t_storage *storage)
{
	rotate(storage->stack_b);
	storage->steps++;
}

void	crr(t_storage *storage)
{
	rotate(storage->stack_a);
	rotate(storage->stack_b);
	storage->steps++;
}
