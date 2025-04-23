#include "push_swap.h"

// struct s_stack *add_to_empty(int nbr, int ei);
// struct s_stack *add_at_end(struct s_stack *tail, int nbr, int ei);
// void quicksort_a(t_stack **a, t_stack **b, int len);
// void quicksort_b(t_stack **a, t_stack **b, int len);
// void	print(struct s_stack *tail);

// helper: compute the size of a circular stack (tail pointer)
// int stack_size(t_stack *tail)
// {
//     if (!tail)
//         return 0;
//     int count = 1;
//     t_stack *current = tail->next;  // head
//     while (current != tail)
//     {
//         count++;
//         current = current->next;
//     }
//     return count;
// }

// void quicksort_a(t_stack **a, t_stack **b, int len)
// {
//     if (len <= 1)
//         return;
//     int pivot = find_median(*a, len);
// 	//printf("\nmedian: %d\n", pivot);

//     int pushed = 0, rotated = 0;
//     for (int i = 0; i < len; i++)
//     {
//         if ((*a)->next->ei <= pivot)
//         {
//             pb(a, b);
//             pushed++;
//         }
//         else
//         {
//             ra(a, 'a');
//             rotated++;
//         }
//     }
//     // undo the rotations so that the order of the “> pivot” block is preserved
//     while (rotated--)
//         rra(a, 'a');

//     // now A has len - pushed elements > pivot, B has pushed elements ≤ pivot
//     quicksort_a(a, b, len - pushed);
//     quicksort_b(a, b, pushed);

//     // reassemble: move the low‐half back onto A
//     while (pushed-- && pushed > 0)
//         pa(b, a);
// }

// void quicksort_b(t_stack **a, t_stack **b, int len)
// {
//     if (len <= 1)
//         return;
//     int pivot = find_median(*b, len);
// 	//printf("\nmedian: %d\n", pivot);

//     int pushed = 0, rotated = 0;
//     for (int i = 0; i < len; i++)
//     {
//         if ((*b)->next->ei > pivot)
//         {
//             pa(b, a);
//             pushed++;
//         }
//         else
//         {
//             ra(b, 'b');
//             rotated++;
//         }
//     }
//     // undo the rotations so that the “≤ pivot” block stays in the same relative order
//     while (rotated--)
//         rra(b, 'b');

//     // now A has pushed elements > pivot, B has len - pushed elements ≤ pivot
//     quicksort_a(a, b, pushed);
//     quicksort_b(a, b, len - pushed);
// }


// int main(void)
// {
//     t_stack *a = NULL;
//    	t_stack *b = NULL;

//     // build stack A with elements and their expected indices
//     a = add_to_empty(10, 10);
//     a = add_at_end(a, 6, 6);
//     a = add_at_end(a, 1, 1);
//     a = add_at_end(a, 3, 3);
//     a = add_at_end(a, 2, 2);
//     a = add_at_end(a, 4, 4);
//     a = add_at_end(a, 8, 8);
//     a = add_at_end(a, 5, 5);
//     a = add_at_end(a, 9, 9);
//     a = add_at_end(a, 7, 7);

//     // initial state
//     printf("Stack A before sort:\n");
//     print(a);
//     printf("Stack B before sort (should be empty):\n");
//   //  print(b);

//     // perform quicksort on A using B as auxiliary
//     int len = stack_size(a);
	
//     quicksort_a(&a, &b, len);

//     // final state
//     printf("Stack A after sort:\n");
//     print(a);
//     printf("Stack B after sort (should be empty again):\n");
//    //	print(b);

//     return 0;
// }
