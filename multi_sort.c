#include "push_swap.h"

void quicksort_a(t_stack **a, t_stack **b, int argn)
{
	int pivot;
	int pushed;
	int rotated;
	int i;
	
	if (argn <= 1)
		return ;
	pivot = find_median(*a, argn);
	pushed = 0;
	rotated = 0;
	i = 0;
	while (i < argn)
	{
		if ((*a)->next->ei <= pivot)
			pb(a, b), pushed++;
		else
			ra(a, 'a'), rotated++;
		i++;
	}
	while (rotated--)
		rra(a, 'a');
	quicksort_a(a, b, argn - pushed);
	quicksort_b(a, b, pushed);
	while(pushed-- && pushed > 0)
		pa(b, a);
}

void	quicksort_b(t_stack **a, t_stack **b, int argn)
{
	int pivot;
	int pushed;
	int rotated;
	int i;

	if (argn <= 1)
		return ;
	pivot = find_median(*b, argn);
	pushed = 0;
	rotated = 0;
	i = 0;
	while (i < argn)
	{
		if ((*b)->next->ei > pivot)
			pa(b, a), pushed++;
		else
			ra(b, 'b'), rotated++;
		i++;
	}
	while (rotated--)
		rra(b, 'b');
	quicksort_a(a, b, pushed);
	quicksort_b(a, b, argn - pushed);
}