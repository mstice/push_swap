#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h> //remove
#include <ctype.h> //remove
#include <string.h> //remove

typedef struct	s_stack
{
	struct s_stack	*prev;
	int				nbr;
	struct s_stack	*next;
	int				ei; //expected index
}				t_stack;

//others
void	ft_error(void);
void	free_list(t_stack **tail, int stack_size);

//input check
char	**input_check(int argc, char **argv); //checks for non-numbers
int		argc_counter(char **strs); //counts argcs, which needs to happen when input is a string
t_stack	*input_stack(int argn, char **argv); //checks for ints, deletes zeroes and doubles

//pre sort
void	assign_index(t_stack **tail_a, int *arr, int argn); //updates expected index onto each node based on sorted array
void	sort_index(t_stack *tail_a, int argn); //puts numbers onto array and sorts them using bubble sort

//stack utils
t_stack	*add_to_empty(int data, int ei); //creates a new node
t_stack	*add_at_beg(t_stack *tail, int data, int ei); //adds a new node at the beginning of the stack
t_stack	*add_at_end(t_stack *tail, int data, int ei); //adds a new node at the end
t_stack	*del_first(t_stack *tail); //deletes the first node
t_stack	*del_last(t_stack *tail); //deletes the last node
void	print(t_stack *tail);

//sorting functions
void	sa(t_stack **tail, char stack_name); //also sb
void	ss(t_stack **tail_a, t_stack **tail_b); //sa and sb at the same time
void	pa(t_stack **tail_b, t_stack **tail_a); //takes first element of b and puts it at the top of a
void	pb(t_stack **tail_a, t_stack **tail_b); //takes first element of a and puts it at the top of b
void	ra(t_stack **tail, char stack_name); //also rb
void	rr(t_stack **tail_a, t_stack **tail_b);
void	rra(t_stack **tail, char stack_name); //also rrb
void	rrr(t_stack **tail_a, t_stack **tail_b);

//mini sort
void	mini_sort(t_stack **a, t_stack **b, int size_a);
void	bi_sort(t_stack **a);
void	tri_sort(t_stack **a);
void	quad_sort(t_stack **a, t_stack **b);
void	quint_sort(t_stack **a, t_stack **b);
//void	sext_sort(t_stack **tail);

//mini revsort
void	mini_revsort(t_stack **b, int size_b);
void	bi_revsort(t_stack **b);
void	tri_revsort(t_stack **b);

//quicksort
void	quicksort_a(t_stack **a, t_stack **b, int size_a);
void	quicksort_b(t_stack **a, t_stack **b, int size_b);

//sorting utils
int		sorted(t_stack *tail); //returns TRUE if stack is sorted in ascending order
int		revsorted(t_stack *tail); //returns TRUE if stack is sorted in descending order
int		getmax(t_stack *tail);
int		getmin(t_stack *tail);
int		find_median(t_stack *tail, int argn);
int		stack_size(t_stack *tail); //TO DELETE

//freeing functions
//void	free_list(t_stack *tail) //make sure to free index_offset when the last node is freed

//TO REMOVE
void	print(t_stack *tail);

#endif