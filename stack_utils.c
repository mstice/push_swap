#include "push_swap.h"

struct s_stack	*add_to_empty(int data, int ei) //adapted to ei
{
	struct s_stack	*new = malloc(sizeof(struct s_stack));

	if (!new)
		return (NULL);
	new -> nbr = data;
	new -> ei = ei;
	new -> next = new;
	new -> prev = new;
	return (new);
}

struct s_stack	*add_at_beg(struct s_stack *tail, int data, int ei) //adapted to ei
{
	struct s_stack *newP = add_to_empty(data, ei);
	struct s_stack *temp;
	
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

struct s_stack	*add_at_end(struct s_stack *tail, int data, int ei) //adapted to ei
{
	struct s_stack *newP = add_to_empty(data, ei);
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
	tail->next = temp->next;
	temp->next->prev = tail;
	free(temp);
	return (tail);
}

struct s_stack	*del_last(struct s_stack *tail)
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
	temp -> next = tail -> next;
	tail -> next -> prev = temp;
	free(tail);
	tail = temp;;
	return (tail);
}

void	print(struct s_stack *tail)
{
	if (tail->next == NULL)
		printf("no element in the list");
	else
	{
		struct s_stack *temp = tail -> next;
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

void	free_list(t_stack **tail)
{
	t_stack *temp;
	int n;

	n = 18;
	while (n > 0)
	{
		temp = (*tail)->next;
		free(temp);
		n--;
	}
}
// int main(void)
// {
// 	struct s_stack *a = NULL;
// 	struct s_stack *b = NULL;
// 	a = add_to_empty(34);
// 	a = add_at_beg(a, 20);
// 	a = add_at_end(a, 72);
// 	a = add_at_end(a, 21);
// 	// a = del_first(a);
// 	// b = add_to_empty(101);
// 	// b = add_at_end(b, 202);
// 	pb(&a, &b);
// 	pb(&a, &b);
// 	if (a == NULL)
// 		printf("List is empty");
// 	else
// 		printf("stack a: "), print(a);
// 	if (b == NULL)
// 		printf("List is empty");
// 	else
// 		printf("stack b: "), print(b);
// 	// else
// 	// {
// 	// 	struct s_stack *temp = a -> next;
// 	// 	printf("%d ", temp -> nbr);
// 	// 	temp = temp -> next;
// 	// 	while (temp != a -> next)
// 	// 	{
// 	// 		printf("%d ", temp -> nbr);
// 	// 		temp = temp -> next;
// 	// 	}
// 	// }
// 	//printf("%d ", sorted(a));
// 	return (0);
// }