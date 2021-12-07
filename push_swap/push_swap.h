/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:07:15 by bmaya             #+#    #+#             */
/*   Updated: 2021/12/07 16:17:08 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_lstack{
	int					number;
	int					order;
	int					flag;
	struct s_lstack		*next;
	struct s_lstack		*prev;
}	t_lstack;

typedef struct s_storage{
	t_lstack	**stack_a;
	t_lstack	**stack_b;
	int			min_number;
	int			max_number;
}	t_storage;

int			stack_size(t_lstack **stack);
int			make_orders(t_lstack **stack);
int			create_first_lstack(t_storage *storage, int argc, char **argv);
int			ft_atoi(const char *str);

t_lstack	*create_node(int number);
void		addback_node(t_lstack **stack, t_lstack *node);
t_lstack	*take_last_node(t_lstack **stack);
t_lstack	*take_first_node(t_lstack **stack);
int			sort_check(t_lstack **stack);

#endif