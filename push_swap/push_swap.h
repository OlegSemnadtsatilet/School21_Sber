/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:07:15 by bmaya             #+#    #+#             */
/*   Updated: 2022/01/20 15:30:40 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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
	int			max_order;
	int			mid_order;
	int			steps;
}	t_storage;

int			stack_size(t_lstack **stack);
int			make_orders(t_lstack **stack);
int			create_first_lstack(t_storage *storage, int argc, char **argv);
long long	ft_atoi(const char *str);

t_lstack	*create_node(int number);
void		addback_node(t_lstack **stack, t_lstack *node);
t_lstack	*take_last_node(t_lstack **stack);
t_lstack	*take_first_node(t_lstack **stack);
int			sort_check(t_lstack **stack);
int			check_duplicates(t_lstack **stack);
void		mini_sorting(t_storage *storage, int argc);
void		sorting(t_storage *storage);

void		swap(t_lstack **stack);
void		rotate(t_lstack **stack);
void		reverse_rotate(t_lstack **stack);
void		push(t_lstack **from_stack, t_lstack **to_stack);

void		sa(t_storage *storage);
void		sb(t_storage *storage);
void		ss(t_storage *storage);
void		pb(t_storage *storage);
void		pa(t_storage *storage);

void		ra(t_storage *storage);
void		rb(t_storage *storage);
void		rr(t_storage *storage);

void		rra(t_storage *storage);
void		rrb(t_storage *storage);
void		rrr(t_storage *storage);

void		push_mid_node(t_storage *storage);
void		push_all_to_b(t_storage *storage);

int			steps_to_top_b(t_storage *storage, t_lstack *node);
int			steps_to_closest_a(t_storage *storage, t_lstack *node);
void		min_flag_b_to_top(t_storage *storage, int b_steps);
void		closest_a_to_top(t_storage *storage, int a_steps);
int			absolute(int value);
void		put_nodes_to_top(t_storage *storage, int a_steps, int b_steps);
void		give_flags(t_storage *storage);
void		push_min_flag(t_storage *storage);
void		last_rotate(t_storage *storage);

void		sorting_three_numbers_a(t_storage *storage);
void		sorting_three_numbers_b(t_storage *storage);
void		merging_two_stacks(t_storage *storage);
void		sorting_between_four_six(t_storage *storage);

void		last_rotate_cicles(t_storage *storage, int steps);
int			check_is_numbers(char **str);
int			error_out_check(char **argv, t_lstack **stack);

#endif