#include "push_swap.h"

t_stack	*add_to_empty(int data, int ei) //adapted to ei
{
	t_stack	*new = malloc(sizeof(t_stack));

	if (!new)
		return (NULL);
	new -> nbr = data;
	new -> ei = ei;
	new -> next = new;
	new -> prev = new;
	return (new);
}

t_stack	*add_at_beg(t_stack *tail, int data, int ei) //adapted to ei
{
	t_stack *newP = add_to_empty(data, ei);
	t_stack *temp;
	
	newP -> ei = ei;
	if (tail == NULL)
		return (newP);
	else
	{
		temp = tail -> next;
		newP -> prev = tail;
		newP -> next = temp;
		temp -> prev = newP;
		tail -> next = newP;
		return (tail);
	}
}

t_stack	*add_at_end(t_stack *tail, int data, int ei) //adapted to ei
{
	t_stack *newP = add_to_empty(data, ei);
	t_stack *temp;
	
	if (tail == NULL)
		return (newP);
	else
	{
		temp = tail -> next;
		newP -> next = temp;
		newP -> prev = tail;
		tail -> next = newP;
		temp -> prev = newP;
		tail = newP;
		return(tail);
	}
}

t_stack	*del_first(t_stack *tail)
{
	t_stack *temp;

	if (tail == NULL)
		return(tail);
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
	temp -> next = tail -> next;
	tail -> next -> prev = temp;
	free(tail);
	tail = temp;;
	return (tail);
}

void	print(t_stack *tail)
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
}