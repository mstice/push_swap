/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <mtice@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:04:13 by mtice             #+#    #+#             */
/*   Updated: 2025/05/16 22:04:54 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **tail_a, t_stack **tail_b)
{
	sa(tail_a, 's');
	sa(tail_b, 's');
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_stack **tail_a, t_stack **tail_b)
{
	ra(tail_a, 'r');
	ra(tail_b, 'r');
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stack **tail_a, t_stack **tail_b)
{
	rra(tail_a, 'r');
	rra(tail_b, 'r');
	ft_putstr_fd("rrr\n", 1);
}

int	sorted(t_stack *tail)
{
	t_stack	*head;

	head = tail -> next;
	while (head != tail && head->nbr < head->next->nbr)
		head = head->next;
	if (head == tail)
		return (1);
	else
		return (0);
}

int	revsorted(t_stack *tail)
{
	t_stack	*head;

	head = tail->next;
	while (head != tail && head->nbr > head->next->nbr)
		head = head->next;
	if (head == tail)
		return (1);
	else
		return (0);
}
