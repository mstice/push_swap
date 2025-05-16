#include "push_swap.h"

// static int    count_push(t_stack **b) //UNTESTED
// {
//     int max_ei;
//     int pos;
//     t_stack *temp;

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
//     // if (pos < stack_size(*b)/2 && max_ei >= find_median(*b, stack_size(*b)))
//     // {
//     //     while(pos > 2)
//     //         ra(b, 'b'), pos--;
//     //     if (pos == 2)
//     //         sa(b, 'b');
//     //     pa(b, a);
//     //     return ;
//     // }
//     // else
//     // {
//     //     while (pos >= stack_size(*b))
//     //         rra(b, 'b'), pos--;
//     //     pa(b, a);
//     // }
// }

// void quicksort_a(t_stack **a, t_stack **b, int size_a)
// {
//     //int pivot;
    
//     if (size_a <= 1 || sorted(*a))
//         return ;
//     else if (size_a <= 5)
//         return (mini_sort(a, b, size_a));
//     //pivot = find_median(*a, size_a);
//     // while (size_a > 5){
//     //     if ((*a)->next->ei >= pivot)
//     //         ra(a, 'a');
//     //     else if ((*a)->next->ei < pivot)
//     //         pb(a, b);
//     //     size_a--;
//     // }
//     while (size_a >= 5)
//     {
//         if ((*a)->next->ei > (getmax(*a) - 5))
//             ra(a, 'a');
//         else
//             pb(a, b);
//         size_a--;
//     }
//     //quicksort_a(a, b, stack_size(*a));
//     quicksort_b(a, b, stack_size(*b));
// }

// void quicksort_b(t_stack **a, t_stack **b, int size_b)
// {
//     //int pivot;
//     //int rbs;
//     int max_pos;
  
//     //rbs = 0;
//     if (size_b == 0)
//         return;
//     if (size_b == 1)
//         return (pa(b, a));
//     else if (size_b <= 3)
//         mini_revsort(b, size_b);
//     //pivot = find_median(*b, size_b);
//     max_pos = count_push(b);
//     while (size_b > 3)
//     {
//         max_pos = count_push(b);
//         if (max_pos < stack_size(*b)/2)
//         {
//             while (max_pos > 2)
//                 ra(b, 'b'), max_pos--;
//             if (max_pos == 2)
//                 sa(b, 'b');
//             pa(b, a);
//         }
//         else //if (max_pos >= stack_size(*b)/2)
//         {
//             while (count_push(b) != stack_size(*b))
//                 rra(b, 'b');
//             rra(b, 'b'), pa(b, a);
//         }
//         size_b--;
//     }
//     return ;
//     // while (size_b > 0)
//     // {
//     //     //maybe some sort of counting function to determine how expensive it is to bring the max number to the head
//     //     if ((*b)->next->ei == getmax(*b) && (*b)->next->ei >= pivot)
//     //         pa(b, a);
//     //     else if ((*b)->next->next->ei == getmax(*b) && (*b)->next->next->ei >= pivot)
//     //         sa(b, 'b'), pa(b, a);
//     //     else if ((*b)->ei == getmax(*b) && (*b)->ei >= pivot)
//     //         rra(b, 'b'), pa(b, a);
//     //     else if ((*b)->prev->ei == getmax(*b) && (*b)->prev->ei >= pivot)
//     //         rra(b, 'b'), rra(b, 'b'), pa(b, a);
//     //     else if (rbs > 1)
//     //         rra(b, 'b');
//     //     else
//     //         ra(b, 'b'), rbs++;
//     //     size_b--;
//     // }
//     // quicksort_a(a, b, stack_size(*a));
//     // quicksort_b(a, b, stack_size(*b));
// }
