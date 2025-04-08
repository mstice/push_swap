#include "push_swap.c"

int	find_median(struct s_stack **tail, int argn)
{
	struct s_stack *temp;
	int				median;

	temp = (*tail) -> next;
	while (temp != (*tail))
	{
		if (temp -> index == (argn / 2))
		{
			median = temp -> nbr;
			break ;
		}
		else
			temp = temp -> next;
	}
	return (median);
}


void multi_sort(struct s_stack **tail, int argn)
{	
	int				median;
	struct s_stack *temp_a;
	struct s_stack *temp_b;
	int				n;

	median = find_median(tail, argn);
	temp_a = (*tail) -> next;
	n = 0;
	while(42) //I have to decide if I am rotating counter-clockwise or clockwise when there is nothing else to do
	{
		if ((temp_a->next->ei - temp_a->ei) == 1)
			sa(&temp_a, 'a');
		else if ((temp_a->prev->ei - temp_a->ei) == 1)
			rra(&temp_a, 'a'), sa(&temp_a, 'a');
		else if ((temp_a->ei - temp_a->prev->ei) == 1)
			ra(&temp_a, 'a');
		else if ((temp_b->next->ei - temp_b->ei) == 1)
			sa(&temp_b, 'b');
		else if ((temp_b->prev->ei - temp_b->ei) == 1)
			rra(&temp_b, 'b'), sa(&temp_b, 'b');
		else if ((temp_b->ei - temp_b->prev->ei) == 1)
			ra(&temp_b, 'b');
		else if ((temp_a->ei - temp_b->ei) == 1)
			pa(&temp_b, &temp_a);
		else if ((temp_b->ei - temp_a->ei) == 1)
			pb(&temp_a, temp_b);
		else
			//something, rotate ra or rra
		if (sorted(temp_a) && sorted(temp_b))
		{
			//merge based on ei of heads
		}	
		//CHECK THAT NONE OF THESE CONDITIONS MAY OCCUR MORE THAN ONCE (to keep else ifs or change to ifs)
	}
}