#include "push_swap.h"

void quicksort_a(t_stack **a, t_stack **b, int argn)
{
    int pivot;
    int small;
    int big;
    int i;
    t_stack *temp = NULL;

    if (argn <= 1 || sorted(*a))
        return ;
    else if (argn <= 4){
        // printf("hello argn is: %d\n", argn);
        mini_sort(a, argn);
        return ;
    }
    pivot = find_median(*a, argn);
    small = 0;
    big = 0;
    i = 0;
    while (i < argn){
        if ((*a)->next->ei < pivot)
            pb(a, b), small++;
        else
            ra(a, 'a'), big++;
        i++;
    }
    // printf("after partition:\n stack a:");
    // print(*a), printf("stack b:"), print(*b);
    quicksort_a(a, &temp, big);
    quicksort_b(&temp, b, small);
    while (small--)
        pa(b, a);
}


void quicksort_b(t_stack **a, t_stack **b, int argn)
{
    int pivot;
    int small;
    int big;
    int i;
    t_stack *temp = NULL;

    if (argn <= 1 || revsorted(*b))
        return;
    else if (argn <= 3){
        //printf("starting mini_revsort\n");
        mini_revsort(b, argn);
        return ;
    }
    pivot = find_median(*b, argn);
    small = 0;
    big = 0;
    i = 0;
    // 1) Partition B  
    //    >pivot → A,  ≤pivot → rb
    while (i < argn)
    {
        if ((*b)->next->ei > pivot)// attempt 3 changes
            pa(b, a), big++;
        else
            ra(b, 'b'), small++; // does rb internally
        i++;
    }
    // printf("after partition:\n stack a:");
    // print(*a), printf("stack b:"), print(*b);
    quicksort_a(a, &temp, big);
    quicksort_b(&temp, b, small);
    while (big--)
        pb(a, b);
}