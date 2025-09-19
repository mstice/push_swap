/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <mtice@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:04:13 by mtice             #+#    #+#             */
/*   Updated: 2025/05/16 22:04:54 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **tail, char stack_name) //adapted to ei
{
	int	data1;
	int	data2;
	int	ei1;
	int	ei2;

	data1 = (*tail)->next->nbr;
	ei1 = (*tail)->next->ei;
	data2 = (*tail)->next->next->nbr;
	ei2 = (*tail)->next->next->ei;
	(*tail)->next->nbr = data2;
	(*tail)->next->ei = ei2;
	(*tail)->next->next->nbr = data1;
	(*tail)->next->next->ei = ei1;
	if (stack_name == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("sb\n", 1);
	else if (stack_name != 'a' && stack_name != 'b' && stack_name != 's')
		ft_putstr_fd("Wrong stack name!", 2);
}

void	pa(t_stack **tail_b, t_stack **tail_a)
{
	t_stack	*head_b;

	if (!tail_b)
		return ;
	head_b = (*tail_b)->next;
	if (*tail_a == NULL)
		(*tail_a) = add_to_empty(head_b->nbr, head_b->ei);
	else
		(*tail_a) = add_at_beg(*tail_a, head_b->nbr, head_b->ei);
	*tail_b = del_first(*tail_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **tail_a, t_stack **tail_b)
{
	t_stack	*head_a;

	if (!tail_a)
		return ;
	head_a = (*tail_a)->next;
	if (*tail_b == NULL)
		(*tail_b) = add_to_empty(head_a->nbr, head_a->ei);
	else
		(*tail_b) = add_at_beg(*tail_b, head_a->nbr, head_a->ei);
	*tail_a = del_first(*tail_a);
	ft_putstr_fd("pb\n", 1);
}

void	ra(t_stack **tail, char stack_name)
{
	int	data1;
	int	ei1;

	data1 = (*tail)->next->nbr;
	ei1 = (*tail)->next->ei;
	*tail = del_first(*tail);
	*tail = add_at_end(*tail, data1, ei1);
	if (stack_name == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("rb\n", 1);
	else if (stack_name != 'a' && stack_name != 'b' && stack_name != 'r')
		ft_putstr_fd("Wrong stack name!", 2);
}

void	rra(t_stack **tail, char stack_name)
{
	int	data1;
	int	ei1;

	data1 = (*tail)->nbr;
	ei1 = (*tail)->ei;
	*tail = del_last(*tail);
	*tail = add_at_beg(*tail, data1, ei1);
	if (stack_name == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("rrb\n", 1);
	else if (stack_name != 'a' && stack_name != 'b' && stack_name != 'r')
		ft_putstr_fd("Wrong stack name!", 2);
}
