/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <mtice@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:49:43 by mtice             #+#    #+#             */
/*   Updated: 2025/06/01 16:25:12 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
//# include <stdio.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				nbr;
	struct s_stack	*next;
	int				ei; //expected index
}				t_stack;

typedef struct s_info
{
	int		small;
	int		big;
	int		pivot;
	int		first;
}				t_info;

//others
void	ft_error(void);
void	free_list(t_stack **tail, int stack_size);

//input check
char	**input_check(int argc, char **argv);
int		argc_counter(char **strs);
t_stack	*input_stack(int argn, char **argv);
void	check_doubles(t_stack *a);

//pre sort
void	assign_index(t_stack **tail_a, int *arr, int argn);
void	sort_index(t_stack *tail_a, int argn);
void	bubble_sort(int *arr, int argn);

//stack utils
t_stack	*add_to_empty(int data, int ei);
t_stack	*add_at_beg(t_stack *tail, int data, int ei);
t_stack	*add_at_end(t_stack *tail, int data, int ei);
t_stack	*del_first(t_stack *tail);
t_stack	*del_last(t_stack *tail);
void	print(t_stack *tail);

//sorting functions1
void	sa(t_stack **tail, char stack_name);
void	pa(t_stack **tail_b, t_stack **tail_a);
void	pb(t_stack **tail_a, t_stack **tail_b);
void	ra(t_stack **tail, char stack_name);
void	rra(t_stack **tail, char stack_name);

//sorting functions2
int		sorted(t_stack *tail);
int		revsorted(t_stack *tail);
void	ss(t_stack **tail_a, t_stack **tail_b);
void	rr(t_stack **tail_a, t_stack **tail_b);
void	rrr(t_stack **tail_a, t_stack **tail_b);

//mini sort
void	mini_sort(t_stack **a, t_stack **b, int size_a);
void	bi_sort(t_stack **a);
void	tri_sort(t_stack **a);
void	quad_sort(t_stack **a, t_stack **b);
void	quint_sort(t_stack **a, t_stack **b);

//mini revsort
void	mini_revsort(t_stack **b, int size_b);
void	bi_revsort(t_stack **b);
void	tri_revsort(t_stack **b);

//quicksort
void	quicksort_a(t_stack **a, t_stack **b, t_info info_a, int size_a);
void	quicksort_b(t_stack **a, t_stack **b, t_info info_b, int size_b);
void	init_struct(t_stack *tail, t_info *info, int size);

//sorting utils
int		getmax(t_stack *tail);
int		getmin(t_stack *tail);
int		find_median(t_stack *tail, int argn);
int		stack_size(t_stack *tail);

#endif
