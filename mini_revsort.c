/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_revsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <mtice@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:09:18 by mtice             #+#    #+#             */
/*   Updated: 2025/05/16 22:09:53 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_revsort(t_stack **b, int size_b)
{
	if (size_b == 2)
		bi_revsort(b);
	else if (size_b == 3)
		tri_revsort(b);
}

void	bi_revsort(t_stack **b)
{
	t_stack	*head;

	if (revsorted(*b))
		return ;
	head = (*b)->next;
	if (head->nbr < (*b)->nbr)
		sa(b, 'b');
}

//123, 132 213, 231, 312
void	tri_revsort(t_stack **b)
{
	int	w;
	int	x;
	int	y;

	if (revsorted(*b))
		return ;
	w = (*b)->next->nbr;
	x = (*b)->next->next->nbr;
	y = (*b)->nbr;
	if (w < x && w < y && x < y)
	{
		sa(b, 'b');
		rra(b, 'b');
	}
	else if (w < x && w < y && x > y)
		ra(b, 'b');
	else if (w > x && w < y)
		rra(b, 'b');
	else if (w < x && w > y)
		sa(b, 'b');
	else if (w > x && w > y && x < y)
	{
		rra(b, 'b');
		sa(b, 'b');
	}
}
