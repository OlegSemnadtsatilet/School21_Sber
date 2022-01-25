/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:44:08 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/20 15:35:14 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char*s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (ss1[i] != ss2[i] || ss1[i] == 0 || ss2[i] == 0)
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

static int	do_opers(t_storage *storage, char *oper)
{
	if (ft_strncmp(oper, "sa\n", 5) == 0)
		csa(storage);
	else if (ft_strncmp(oper, "sb\n", 5) == 0)
		csb(storage);
	else if (ft_strncmp(oper, "ss\n", 5) == 0)
		css(storage);
	else if (ft_strncmp(oper, "pa\n", 5) == 0)
		cpa(storage);
	else if (ft_strncmp(oper, "pb\n", 5) == 0)
		cpb(storage);
	else if (ft_strncmp(oper, "ra\n", 5) == 0)
		cra(storage);
	else if (ft_strncmp(oper, "rb\n", 5) == 0)
		crb(storage);
	else if (ft_strncmp(oper, "rra\n", 5) == 0)
		crra(storage);
	else if (ft_strncmp(oper, "rrb\n", 5) == 0)
		crrb(storage);
	else if (ft_strncmp(oper, "rr\n", 5) == 0)
		crr(storage);
	else if (ft_strncmp(oper, "rrr\n", 5) == 0)
		crrr(storage);
	else
		return (1);
	return (0);
}

static void	get_opers(t_storage *storage)
{
	char	*oper;

	while (1)
	{
		oper = get_next_line(0);
		if (oper == NULL)
		{
			if (sort_check(storage->stack_a) == 1 && \
			stack_size(storage->stack_b) == 0)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			break ;
		}
		if (do_opers(storage, oper))
		{
			write(1, "Error\n", 6);
			free(oper);
			return ;
		}
		free(oper);
	}
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
	get_opers(storage);
	free_all(storage);
	return (1);
}
