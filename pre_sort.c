/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <mtice@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:05:46 by mtice             #+#    #+#             */
/*   Updated: 2025/05/16 22:08:10 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack **tail_a, int *arr, int argn)
{
	t_stack	*temp;
	int		i;

	temp = (*tail_a)->next;
	i = 0;
	while (i != argn)
	{
		if (temp -> nbr == arr[i])
		{
			temp -> ei = i + 1;
			i++;
		}
		else
			temp = temp -> next;
	}
	return ;
}

//takes stack and puts it into array
//bubble sorts temp array
void	sort_index(t_stack *tail_a, int argn)
{
	int				arr[50000];
	t_stack			*temp;
	int				i;

	i = 0;
	temp = tail_a->next;
	while (i < argn)
	{
		arr[i] = temp -> nbr;
		temp = temp -> next;
		i++;
	}
	bubble_sort(arr, argn);
	assign_index(&tail_a, arr, argn);
}

void	bubble_sort(int *arr, int argn)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < argn)
	{
		j = 0;
		while (j < (argn - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}
