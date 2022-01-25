/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:13:57 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/20 14:51:57 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_first_lstack(t_storage *storage, int argc, char **argv)
{
	int			counter;
	long long	number;
	int			max_int;
	int			min_int;

	max_int = 2147483647;
	min_int = -2147483648;
	counter = 0;
	number = 0;
	while (++counter < argc)
	{
		number = ft_atoi(argv[counter]);
		if (number > max_int || number < min_int)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		else
			addback_node(storage->stack_a, create_node(ft_atoi(argv[counter])));
	}
	storage->max_order = stack_size(storage->stack_a) - 1;
	storage->mid_order = storage->max_order / 2;
	storage->steps = 0;
	return (0);
}

int	stack_size(t_lstack **stack)
{
	int			size;
	t_lstack	*iter_node;

	if (!*stack)
		return (0);
	iter_node = *stack;
	size = 0;
	while ((iter_node)->next)
	{
		iter_node = (iter_node)->next;
		size++;
	}
	size++;
	return (size);
}

int	check_duplicates(t_lstack **stack)
{
	int			*numbers;
	int			i;
	int			j;
	int			flag;
	t_lstack	*iter_node;

	i = 0;
	flag = 0;
	numbers = malloc(sizeof(int) * (stack_size(stack) + 1));
	iter_node = *stack;
	while (iter_node)
	{
		j = 0;
		while (j < i && i > 0)
		{
			if (numbers[j++] == iter_node->number)
				flag = 1;
		}
		numbers[i] = iter_node->number;
		i++;
		iter_node = iter_node->next;
	}
	free(numbers);
	return (flag);
}

int	check_is_numbers(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < 48 || str[i][j] > 57) && \
			(str[i][j] != '-' && str[i][j] != '+'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	error_out_check(char **argv, t_lstack **stack)
{
	if (check_is_numbers(argv) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else if (check_duplicates(stack) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}
