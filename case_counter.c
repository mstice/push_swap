#include "push_swap.h"

// int	case_counter(int ei, struct s_stack *tail_a, struct s_stack *tail_b)
// {
// 	int p; //depending on the position, it will take more moves to execute
// 	struct s_stack *temp_a;
// 	p = 0;
// 	temp_a = tail_a->next;
// 	if (ei == temp_a->ei)
// 		p = 1;
// 	while (ei != tail_a->next->ei) //median of a stack
// 	{
// 		temp_a = temp_a->next;
// 		p++;
// 		if (ei == temp_a->ei)
// 			break ;
// 	}
// 	if (ei > tail_b->next->ei)
// 		return (p);
// 	else if (ei < tail_b->next->ei)
// 	{
// 		if (ei > tail_b->next->next->ei)
// 			return(p + 1);
// 		else if (ei < tail_b->next->next->ei)
// 			return(p + 1);
// 	}
// 	return (p);
// }

int	case_counter(int ei, int p, struct s_stack *tail_b)
{
	if (ei > tail_b->next->ei)
		return (p);
	else if (ei < tail_b->next->ei)
	{
		if (ei > tail_b->next->next->ei)
		{	
			
			return(p + 1);
		}
		else if (ei < tail_b->ei)
		{
			printf("hello");
			return(p + 1);
		}
	}
	else
		return (0);
	return (0);
}

// int main(void)
// {
// 	struct s_stack *a = NULL;
// 	//struct s_stack *b = NULL;
	
// 	a = add_to_empty(10, 10);
// 	a = add_at_end(a, 6, 6);
// 	a = add_at_end(a, 1, 1);
// 	a = add_at_end(a, 3, 3);
// 	a = add_at_end(a, 2, 2);
// 	a = add_at_end(a, 4, 4);
// 	a = add_at_end(a, 8, 8);
// 	a = add_at_end(a, 5, 5);
// 	a = add_at_end(a, 9, 9);
// 	a = add_at_end(a, 7, 7);
// 	print(a);
// 	// b = add_to_empty(7, 7);
// 	// b = add_at_end(b, 6, 6);
// 	// b = add_at_end(b, 1, 1);
// 	// print(b);
// 	// struct s_stack *temp;
// 	// temp = a->next;
// 	// int ei = a->next->ei;
// 	// int bc = 0;
// 	// while (case_counter(ei, a, b) == 0)
// 	// {
// 	// 	a = a -> next;
// 	// 	ei = a->next->ei;
// 	// }
// 	// if (case_counter(a->next->ei, a->next, b) != 0 && case_counter(a->next->ei, a->next, b) < bc)
// 	// 	bc = case_counter(a->next->ei, a->next, b);
// 	//printf("best case: %d\n", case_counter(a->next->next->ei, 2, b));
// 	//multi_sort(&a, 9);
// 	quicksort(&a, 10);
// 	//printf("find median: %d\n", find_median(a, 4));
// 	return (0);	
// }