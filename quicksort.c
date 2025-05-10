#include "push_swap.h"

void quicksort_a(t_stack **a, t_stack **b, int size_a)
{
    int pivot;
    int ras;

    ras = 0;
    if (size_a <= 1 || sorted(*a))
        return ;
    else if (size_a <= 5){
        mini_sort(a, b, size_a);
        return ;
    }
    pivot = find_median(*a, size_a);
    while (size_a > 0){
        if ((*a)->next->ei >= pivot)
            ra(a, 'a'), ras++;
        else //if ((*a)->next->ei < pivot)
           pb(a, b);
        size_a--;
    }
    quicksort_a(a, b, stack_size(*a));
    quicksort_b(a, b, stack_size(*b));
}


void quicksort_b(t_stack **a, t_stack **b, int size_b)
{
    int pivot;
    int rbs;
  
    rbs = 0;
    if (size_b == 0)
        return;
    else if (size_b <= 3)
        mini_revsort(b, size_b);
    pivot = find_median(*b, size_b);
    while (size_b > 0)
    {
        if ((*b)->next->ei == getmax(*b) && (*b)->next->ei >= pivot)
            pa(b, a);
        else if ((*b)->next->next->ei == getmax(*b) && (*b)->next->next->ei >= pivot)
            sa(b, 'b'), pa(b, a);
        else
            ra(b, 'b'), rbs++;
        size_b--;
    }
    quicksort_a(a, b, stack_size(*a));
    quicksort_b(a, b, stack_size(*b));
}
