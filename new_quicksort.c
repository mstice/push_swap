#include "push_swap.h"

// static int    count_push(t_stack **b)
// {
//     int max_ei;
//     int pos;
//     t_stack *templ;
//     max_ei = getmax(*b);
//     pos = 1;
//     temp = (*b)->next;
//     while (temp != (*b))
//     {
//         if (temp->ei == max_ei)
//             break ;
//         temp = temp->next;
//         pos++;
//     }
//     return (pos);
// }

static void revsorted_seg(t_stack **b, int argn)
{
	int w;
	int x;
	int y;

	w = (*b)->next->ei;
	x = (*b)->next->next->ei;
	y = (*b)->next->next->next->ei;
	if (argn == 3)
	{
		if (w < x && x < y) //1 2 3
			sa(b, 'b'), ra(b, 'b'), sa(b, 'b'), rra(b, 'b'), sa(b, 'b');
		else if (w < x && w < y && x > y) //1 3 2
			sa(b, 'b'), ra(b, 'b'), sa(b, 'b'), rra(b, 'b');
		else if (w > x && w < y) //2 1 3
			ra(b, 'b'), sa(b, 'b'), rra(b, 'b'), sa(b, 'b');
		else if (w < x && w > y) //2 3 1
			sa(b, 'b');
		else if (w > x && w > y && x < y) // 3 1 2
			ra(b, 'b'), sa(b, 'b'), rra(b, 'b');
		if (w > x && x > y) //3 2 1
			return ;
	}
	if (argn == 2)
	{
		if (w < x)
			sa(b, 'b');
		if (w > x)
			return ;
	}
}

static void sorted_seg(t_stack **a, int argn)
{
	int w;
	int x;
	int y;

	w = (*a)->next->ei;
	x = (*a)->next->next->ei;
	y = (*a)->next->next->next->ei;
	if (argn == 2){
		if (w > x)
			sa(a, 'a');
		if (w < x)
			return ;
	}
	else if (argn == 3){
		if (w < x && w < y && x > y) //1 3 2
			ra(a, 'a'), sa(a, 'a'), rra(a, 'a');
		else if (w > x && w < y) // 2 1 3
			sa(a, 'a');
		else if (w < x && w > y) // 2 3 1
			ra(a, 'a'), sa(a, 'a'), rra(a, 'a'), sa(a, 'a');
		else if (w > x && w > y && x < y) //3 1 2
			sa(a, 'a'), ra(a, 'a'), sa(a, 'a'), rra(a, 'a');
		else if (w > x && w > y && x > y) // 3 2 1
			ra(a, 'a'), sa(a, 'a'), rra(a, 'a'), sa(a, 'a');
		if (w < x && x < y) //1 2 3
			return ;
	}
}

void quicksort_a(t_stack **a, t_stack **b, int argn)
{
    int pivot;
    int small = 0;
    int big = 0;

    if (argn <= 1 || sorted(*a))
        return;
    else if (argn <= 3){
		sorted_seg(a, argn);
        return;
    }
    pivot = find_median(*a, argn);
    int i = argn;
    while (i > 0)
    {
        if ((*a)->next->ei < pivot)
            pb(a, b), small++;
        else
            ra(a, 'a'), big++;
        i--;
    }
    while (big > 0) // Reverse the 'big' elements we rotated
        rra(a, 'a'), big--;
    quicksort_a(a, b, argn - small); //argn - small // 'big' was decremented, but this is how many stayed in A
    quicksort_b(a, b, small); //small
    while (small > 0 && *b)
    {
        if ((*b)->next->ei == getmax(*b))
            pa(b, a), small--;
        else if ((*b)->next->next->ei == getmax(*b))
            sa(b, 'b'), pa(b, a), small--;
        else if ((*b)->ei == getmax(*b))
            rra(b, 'b'), pa(b, a), small--;
        else
            ra(b, 'b');
    }
}

void quicksort_b(t_stack **a, t_stack **b, int argn)
{
    int pivot;
    int small = 0;
    int big = 0;

    if (argn <= 1 || revsorted(*b))
        return;
    else if (argn <= 3)
    {
		revsorted_seg(b, argn);
        return;
    }
    pivot = find_median(*b, argn);
    int i = argn;
    while (i > 0)
    {
        if ((*b)->next->ei > pivot)
            pa(b, a), big++;
        else
            ra(b, 'b'), small++;
        i--;
    }
    while (small > 0)
        rra(b, 'b'), small--;
    quicksort_a(a, b, big); //big
    quicksort_b(a, b, argn - big); //argn - big // or pass 'small' if clearer
    while (big > 0 && *a)
    {
        if (revsorted(*b))
            return ;
        if ((*a)->next->ei == getmin(*a))
            pb(a, b), big--;
        else if ((*a)->next->next->ei == getmin(*a))
            sa(a, 'a'), pb(a, b), big--;
        else if ((*a)->ei == getmin(*a))
            rra(a, 'a'), pb(a, b), big--;
        else
            ra(a, 'a');
    }
}