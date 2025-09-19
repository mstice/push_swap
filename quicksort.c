/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <mtice@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:49:43 by mtice             #+#    #+#             */
/*   Updated: 2025/05/16 21:56:06 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//123, 132, 213, 231, 312, 321
static void	revsorted_seg(t_stack **b, int argn)
{
	int	w;
	int	x;
	int	y;

	w = (*b)->next->ei;
	x = (*b)->next->next->ei;
	y = (*b)->next->next->next->ei;
	if (argn == 2 && w < x)
		return (sa(b, 'b'));
	else if (argn == 3 && !(w > x && x > y))
	{
		if (w < x && x < y)
			return (sa(b, 'b'), ra(b, 'b'), sa(b, 'b'), rra(b, 'b'),
				sa(b, 'b'));
		else if (w < x && w < y && x > y)
			return (sa(b, 'b'), ra(b, 'b'), sa(b, 'b'), rra(b, 'b'));
		else if (w > x && w < y)
			return (ra(b, 'b'), sa(b, 'b'), rra(b, 'b'), sa(b, 'b'));
		else if (w < x && w > y)
			return (sa(b, 'b'));
		else if (w > x && w > y && x < y)
			return (ra(b, 'b'), sa(b, 'b'), rra(b, 'b'));
	}
}

//132, 213, 231, 312, 321
static void	sorted_seg(t_stack **a, int argn)
{
	int	w;
	int	x;
	int	y;

	w = (*a)->next->ei;
	x = (*a)->next->next->ei;
	y = (*a)->next->next->next->ei;
	if (argn == 2 && w > x)
		return (sa(a, 'a'));
	else if (argn == 3 && !(w < x && x < y))
	{
		if (w < x && w < y && x > y)
			return (ra(a, 'a'), sa(a, 'a'), rra(a, 'a'));
		else if (w > x && w < y)
			return (sa(a, 'a'));
		else if (w < x && w > y)
			return (ra(a, 'a'), sa(a, 'a'), rra(a, 'a'), sa(a, 'a'));
		else if (w > x && w > y && x < y)
			return (sa(a, 'a'), ra(a, 'a'), sa(a, 'a'), rra(a, 'a'));
		else if (w > x && w > y && x > y)
			return (sa(a, 'a'), ra(a, 'a'), sa(a, 'a'), rra(a, 'a'),
				sa(a, 'a'));
	}
}

void	init_struct(t_stack *tail, t_info *info, int size)
{
	info->small = 0;
	info->big = 0;
	info->pivot = find_median(tail, size);
	info->first = 0;
}

void	quicksort_a(t_stack **a, t_stack **b, t_info info_a, int size_a)
{
	if (size_a <= 1 || sorted(*a))
		return ;
	else if (size_a <= 3)
		return (sorted_seg(a, size_a));
	init_struct(*a, &info_a, size_a);
	while (size_a--)
	{
		if ((*a)->next->ei < info_a.pivot && ++info_a.small)
			pb(a, b);
		else
		{
			if (info_a.big++ == 0)
				info_a.first = (*a)->next->ei;
			ra(a, 'a');
		}
	}
	while ((*a)->next->ei != info_a.first)
		rra(a, 'a');
	quicksort_a(a, b, info_a, info_a.big);
	quicksort_b(a, b, info_a, info_a.small);
}

void	quicksort_b(t_stack **a, t_stack **b, t_info info_b, int size_b)
{
	if (size_b <= 3 || revsorted(*b))
	{
		revsorted_seg(b, size_b);
		while (size_b--)
			pa(b, a);
		return ;
	}
	init_struct(*b, &info_b, size_b);
	while (size_b--)
	{
		if ((*b)->next->ei >= info_b.pivot && ++info_b.big)
			pa(b, a);
		else
		{
			if (info_b.small++ == 0)
				info_b.first = (*b)->next->ei;
			ra(b, 'b');
		}
	}
	while ((*b)->next->ei != info_b.first)
		rra(b, 'b');
	quicksort_a(a, b, info_b, info_b.big);
	quicksort_b(a, b, info_b, info_b.small);
}
