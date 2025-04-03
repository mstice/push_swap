#include "push_swap.h"

struct s_stack *add_to_empty(int data)
{
	struct s_stack	*new = malloc(sizeof(struct s_stack));

	new -> prev = new;
	new -> nbr = data;
	new -> next = new;
	return (new);
}

struct s_stack	*add_at_beg(struct s_stack *tail, int data)
{
	struct s_stack *newP = add_to_empty(data);
	struct s_stack *temp;

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

struct s_stack *add_at_end(struct s_stack *tail, int data)
{
	struct s_stack *newP = add_to_empty(data);
	struct s_stack *temp;

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

struct s_stack	*del_first(struct s_stack *tail)
{
	struct s_stack *temp;

	if (tail == NULL)
		return(tail);
	temp = tail -> next;
	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	tail -> next = temp -> next;
	temp -> next -> prev = tail;
	return (free(temp), tail);
}

struct s_stack *del_last(struct s_stack *tail)
{
	struct s_stack	*temp;

	if (tail == NULL)
		return (tail);
	temp = tail -> prev;
	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	//temp = tail -> prev;
	temp -> next = tail -> next;
	tail -> next -> prev = temp;
	free(tail);
	tail = temp;;
	return (tail);
}

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

// int main(void)
// {
// 	struct s_stack *a;
	
// 	a = add_to_empty(34);
// 	a = add_at_beg(a, 20);
// 	a = add_at_end(a, 72);
// 	a = add_at_end(a, 21);
// 	//a = del_last(a);
// 	//a = del_first(a);

// 	if (a == NULL)
// 		printf("List is empty"), exit(1);
// 	else
// 	{
// 		struct s_stack *temp = a -> next;
// 		printf("%d ", temp -> nbr);
// 		temp = temp -> next;
// 		while (temp != a -> next)
// 		{
// 			printf("%d ", temp -> nbr);
// 			temp = temp -> next;
// 		}
// 	}
// 	printf("%d ", sorted(a));
// 	return (0);
// }