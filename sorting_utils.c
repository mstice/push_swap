#include "push_swap.h"

int	sorted(struct s_stack *tail)
{
	struct s_stack *head;

	head = tail -> next;
	while (head != tail && head -> nbr < head -> next -> nbr)
		head = head -> next;
	if (head == tail)
		return (1);
	else //if (head != tail && head -> nbr >= head -> next -> nbr)
		return (0);
}

int	revsorted(struct s_stack *tail)
{
	struct s_stack *head;

	head = tail -> next;
	while (head != tail && head -> nbr > head -> next -> nbr)
		head = head -> next;
	if (head == tail)
		return (1);
	else //if (head != tail && head -> nbr >= head -> next -> nbr)
		return (0);
}

int getmax(t_stack *tail)
{
	struct s_stack *temp;
	int				max;

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

int getmin(t_stack *tail)
{
	struct s_stack *temp;
	int				min;

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

int find_median(struct s_stack *tail, int argn)
{
	int 			min;
	int 			max;
	struct s_stack *temp;
	int				median;

	if (argn < 0)
		return (0);
	min = getmin(tail);
	//printf("hello, min:%d ", min);
	max = getmax(tail);
	//printf("hello, max:%d ", max);
	temp = tail->next;
	while (temp->ei != min && temp->ei != max && temp != tail)
		temp = temp->next;
	if (temp->ei == min)
		median = temp->ei + argn/2;
	else if (temp->ei == max)
		median = temp->ei - argn/2;
	return (median);
}

int stack_size(t_stack *tail)
{
	int count;

    if (!tail)
        return 0;
    count = 1;
    t_stack *current = tail->next;  // head
    while (current != tail)
    {
        count++;
        current = current->next;
    }
    return count;
}