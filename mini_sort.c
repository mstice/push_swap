/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <mtice@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:08:38 by mtice             #+#    #+#             */
/*   Updated: 2025/05/16 22:08:58 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_stack **a, t_stack **b, int size_a)
{
	if (size_a == 2)
		bi_sort(a);
	else if (size_a == 3)
		tri_sort(a);
	else if (size_a == 4)
		quad_sort(a, b);
	else if (size_a == 5)
		quint_sort(a, b);
}

void	bi_sort(t_stack **a)
{
	t_stack	*head;

	if (sorted(*a))
		return ;
	head = (*a)->next;
	if (head->nbr > (*a)->nbr)
		sa(a, 'a');
	return ;
}

//213, 231, 312, 321
void	tri_sort(t_stack **a)
{
	int	w;
	int	x;
	int	y;

	if (sorted(*a))
		return ;
	w = (*a)->next->nbr;
	x = (*a)->next->next->nbr;
	y = (*a)->nbr;
	if (w < x && w < y && x > y)
		return (rra(a, 'a'), sa(a, 'a'));
	else if (w > x && w < y)
		return (sa(a, 'a'));
	else if (w < x && w > y)
		return (rra(a, 'a'));
	else if (w > x && w > y && x < y)
		return (ra(a, 'a'));
	else if (w > x && w > y && x > y)
		return (sa(a, 'a'), rra(a, 'a'));
}

//if w is 2, if w is 3, if w is 4
void	quad_sort(t_stack **a, t_stack **b)
{
	int	w;
	int	x;
	int	y;
	int	z;

	if (sorted(*a))
		return ;
	w = (*a)->next->nbr;
	x = (*a)->next->next->nbr;
	y = (*a)->prev->nbr;
	z = (*a)->nbr;
	pb(a, b);
	tri_sort(a);
	pa(b, a);
	if ((w < x && w < y && w > z)
		|| (w < x && w > y && w < z) || (w > x && w < y && w < z))
		return (sa(a, 'a'));
	else if ((w > x && w > y && w < z)
		|| (w > x && w < y && w > z) || (w < x && w > y && w > z))
		return (rra(a, 'a'), sa(a, 'a'), ra(a, 'a'), ra(a, 'a'));
	else if (w > x && w > y && w > z)
		return (ra(a, 'a'));
}

void	quint_sort(t_stack **a, t_stack **b)
{
	int	pushed;
	int	pivot;

	if (sorted(*a))
		return ;
	pushed = 0;
	pivot = find_median(*a, 5);
	while (pushed != 2)
	{
		if ((*a)->next->ei < pivot)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a, 'a');
	}
	tri_sort(a);
	if ((*b)->next->ei < (*b)->next->next->ei)
		sa(b, 'b');
	pa(b, a);
	pa(b, a);
}
