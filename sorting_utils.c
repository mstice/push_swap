/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <mtice@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:08:38 by mtice             #+#    #+#             */
/*   Updated: 2025/05/16 22:08:58 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getmax(t_stack *tail)
{
	t_stack	*temp;
	int		max;

	temp = tail->next;
	max = temp->ei;
	while (temp != tail)
	{
		if (temp->ei > max)
			max = temp->ei;
		temp = temp->next;
	}
	if (temp->ei > max)
		max = temp->ei;
	return (max);
}

int	getmin(t_stack *tail)
{
	t_stack	*temp;
	int		min;

	temp = tail->next;
	min = temp->ei;
	while (temp != tail)
	{
		if (temp->ei < min)
			min = temp->ei;
		temp = temp->next;
	}
	if (temp->ei < min)
		min = temp->ei;
	return (min);
}

int	find_median(t_stack *tail, int argn)
{
	int				min;
	int				max;
	int				median;
	t_stack			*temp;

	if (argn < 0)
		return (0);
	min = getmin(tail);
	max = getmax(tail);
	temp = tail->next;
	while (temp->ei != min && temp->ei != max && temp != tail)
		temp = temp->next;
	if (temp->ei == min)
		median = temp->ei + argn / 2;
	else
		median = temp->ei - argn / 2;
	return (median);
}

int	stack_size(t_stack *tail)
{
	int		count;
	t_stack	*current;

	if (!tail)
		return (0);
	count = 1;
	current = tail->next;
	while (current != tail)
	{
		count++;
		current = current->next;
	}
	return (count);
}
