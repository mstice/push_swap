/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <mtice@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:08:38 by mtice             #+#    #+#             */
/*   Updated: 2025/06/01 16:17:55 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_to_empty(int data, int ei)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = data;
	new->ei = ei;
	new->next = new;
	new->prev = new;
	return (new);
}

t_stack	*add_at_beg(t_stack *tail, int data, int ei)
{
	t_stack	*newp;
	t_stack	*temp;

	newp = add_to_empty(data, ei);
	newp -> ei = ei;
	if (tail == NULL)
		return (newp);
	else
	{
		temp = tail->next;
		newp->prev = tail;
		newp->next = temp;
		temp->prev = newp;
		tail->next = newp;
		return (tail);
	}
}

t_stack	*add_at_end(t_stack *tail, int data, int ei)
{
	t_stack	*newp;
	t_stack	*temp;

	newp = add_to_empty(data, ei);
	if (tail == NULL)
		return (newp);
	else
	{
		temp = tail->next;
		newp->next = temp;
		newp->prev = tail;
		tail->next = newp;
		temp->prev = newp;
		tail = newp;
		return (tail);
	}
}

t_stack	*del_first(t_stack *tail)
{
	t_stack	*temp;

	if (tail == NULL)
		return (tail);
	temp = tail -> next;
	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	tail->next = temp->next;
	temp->next->prev = tail;
	free(temp);
	return (tail);
}

t_stack	*del_last(t_stack *tail)
{
	t_stack	*temp;

	if (tail == NULL)
		return (tail);
	temp = tail -> prev;
	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	temp->next = tail->next;
	tail->next->prev = temp;
	free(tail);
	tail = temp;
	return (tail);
}
/*
void	print(t_stack *tail) //TO DELTE
{
	if (tail->next == NULL)
		printf("no element in the list");
	else
	{
		t_stack *temp = tail -> next;
		do
		{
			printf(" %d", temp -> nbr);
			printf("(ei:%d)", temp -> ei);
			temp = temp -> next;
		} while (temp != tail -> next);
	}
	printf("\nsorted: %d ", sorted(tail));
	printf("revsorted: %d\n", revsorted(tail));
}*/
