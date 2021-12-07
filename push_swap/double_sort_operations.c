/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sort_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:04:38 by bmaya             #+#    #+#             */
/*   Updated: 2021/12/04 13:39:11 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	double_swap(t_lstack **stack_one, t_lstack **stack_two)
{
	swap(t_lstack **stack_one);
	swap(t_lstack **stack_two);
}

void	double_rotate(t_lstack **stack_one, t_lstack **stack_two)
{
	rotate(stack_one);
	rotate(stack_two);
}

void	double_reverse_rotate(t_lstack **stack_one, t_lstack **stack_two)
{
	reverse_rotate(stack_one);
	reverse_rotate(stack_two);
}
