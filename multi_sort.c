#include "push_swap.h"
// void quicksort(struct s_stack **a, int argn)
// {
// 	int median;
// 	int n;

// 	if (sorted(*a) || argn == 0)
// 		return ;
// 	median = find_median(*a, argn);
// 	n = argn;
// 	while (n > 0)
// 	{
// 		if ((*a)->next->ei > median)
// 			ra(a, 'a');
// 		else if ((*a)->next->ei <= median)
// 		{
// 			if ((*a)->next->ei > (*a)->next->next->ei)
// 				sa(a, 'a');
// 			else
// 				ra(a, 'a');
// 		}
// 		n--;
// 	}
// 	printf("stack a:"), print(*a);
// }

void quicksort(struct s_stack **a, int argn)
{
	int median;
	int n = argn;
	struct s_stack *b = NULL;

	if (sorted(*a) && sorted(b))
		return ;
	if (argn == 1)
		return ;
	median = find_median(*a, n);
	//stack partition
	while (n > 0)
	{
		if ((*a)->next->ei > median)
			pb(a, &b);
		else
			ra(a, 'a');
		n--;
	}
	printf("stack a:"), print(*a), printf("stack b:"), print(b);
	
	//quicksort stack a
	n = 5;
	median = find_median(*a, n);
	while (n > 0)
	{
		if ((*a)->next->ei > median)
			ra(a, 'a');
		if ((*a)->next->ei <= median)
		{
			if ((*a)->next->next->ei > median)
				sa(a, 'a'), ra(a, 'a');
			else if ((*a)->next->next->next->ei > median)
				ra(a, 'a');
		}
		n--;
	}
	
	//quicksort stack b;
	n = 5;
	median = find_median(b, n);
	while (n > 0)
	{
		if (b->next->ei > median)
			ra(&b, 'b');
		if (b->next->ei <= median)
		{
			if (b->next->ei > b->next->next->ei)
				sa(&b, 'b');
			else if (b->ei <= median)
				rra(&b, 'b');
			else if (b->ei > median)
				ra(&b, 'b');
		}
		n--;
	}
	printf("stack a:"), print(*a), printf("stack b:"), print(b);
}


// void	multi_sort(struct s_stack **a, int argn)
// {
// 	struct s_stack *b = NULL;
// 	struct s_stack *temp_a;
// 	int bc = 0;
// 	int p = 1;

// 	if (argn < 0)
// 		return ;
// 	pb(a, &b), pb(a, &b);
// 	if (!rev_sorted(b))
// 		sa(&b, 'b');
// 	temp_a = (*a);
// 	while (!sorted(*a))
// 	{
// 		while (case_counter(temp_a->next->ei, p, b) == 0)
// 		{
// 			temp_a = temp_a->next;
// 			p++;
// 			if (temp_a = a)
// 				break;
// 		}
// 		bc = case_counter(temp_a->next->ei, p, b);
// 		// printf("\n[bc:%d p:%d] ", bc, p);
// 		if (p == bc)
// 		{
// 			while(p != 1)
// 				ra(a, 'a'), p--;
// 			pb(a, &b);
// 		}
// 		else if ((p + 1) == bc)
// 		{
// 			while (p != 1)
// 				ra(a, 'a'), p--;
// 			pb(a, &b);
// 			// printf("\ntemp_a->ei: %d", temp_a->ei);
// 			// printf("b->next->next->ei: %d", b->next->next->ei);
// 			if (b->next->ei > b->next->next->next->ei)
// 			{
// 				if (bc == 2)
// 					sa(&b, 'b');
// 				while (bc != 2)
// 					sa(&b, 'b'), bc--;
// 			}
// 			else if (b->next->ei < b->ei)
// 			{
// 				if (bc == 2)
// 					ra(&b, 'b');
// 				while (bc != 2)
// 					ra(&b, 'b'), bc--;
// 			}
// 		}
// 		print((*a)), print(b);
// 	}
// 	// if (sorted(*a) && rev_sorted(b))
// 	// {
// 	// 	while (b != NULL)
// 	// 	{
// 	// 		if ((*a)->next->ei - b->next->ei == 1)
// 	// 			pa(&b, a);
// 	// 		ra(&b, 'b');
// 	// 	}
// 	// }
// 	printf("\n"), print(*a), print(b);
// 	return ;
// 	// if (is_tri(*a))
// 	// 	tri_sort(a);
// 	// if (!rev_sorted(b))
// 	// 	ft_putstr_fd("Something went wrong", 2), exit(1);
	
// }

// void multi_sort(struct s_stack **tail, int argn)
// {	
// 	struct s_stack *temp_a = NULL;
// 	struct s_stack *temp_b = NULL;
// 	int				n;
// 	int				mod;

// 	if (argn < 1)
// 		ft_error();
// 	temp_a = (*tail) -> next;
// 	n = argn;
// 	mod = 10;
// 	while (n > (argn/2))
// 	{
// 		if ((temp_a->next->ei - temp_a->ei) == 1)
// 			temp_a = temp_a->next;
// 		else
// 			pb(&temp_a, &temp_b), n--;//initialises stack *b
// 	}
// 	printf("\nstack b:");
// 	print(temp_b);
// 	while (!sorted(a, n) && !sorted(b, argn - n))
// 	{
// 		while () //mod 10s
				
// 		}
// 		while () //mod 100s
// 		while () //mod 1000s
// 	}
// 	printf("done");
// 	if (sorted(temp_a, n) && sorted(temp_b, n))
// 	{
// 		while (temp_b != NULL)
// 		{
// 			if ((temp_a->ei - temp_b->ei) == 1)
// 				pa(&temp_b, &temp_a);
// 			ra(&temp_b, 'b');
// 		}
// 	}
// 	if (sorted(temp_a, n))
// 		return ;
// 	// if (temp_b->next == NULL && sorted(temp_a))
// 	// 	return ;
// 	else
// 		ft_putstr_fd("Multi sort didn't sort", 1);
// 	return ;
// 	//CHECK THAT NONE OF THESE CONDITIONS MAY OCCUR MORE THAN ONCE (to keep else ifs or change to ifs)
// }