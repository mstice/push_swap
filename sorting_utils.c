#include "push_swap.h"

bool	sorted(struct s_stack *tail)
{
	struct s_stack *head;

	head = tail -> next;
	
	while ((head != tail) && head -> nbr < head -> next -> nbr)
		head = head -> next;
	if (head == tail)
		return (1);
	else //if (head != tail && head -> nbr >= head -> next -> nbr)
		return (0);
}