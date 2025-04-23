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

//checking the input is valid and processing the input
void			ft_error(void);
char			**input_check(int argc, char **argv); //checks for non-numbers
int				argc_counter(char **strs); //counts argcs, which needs to happen when input is a string
struct s_stack	*input_stack(int argc, char **argv); //checks for ints, deletes zeroes and doubles

//pre sort
void	assign_index(struct s_stack **tail_a, int *arr, int argn); //updates expected index onto each node based on sorted array
void	sort_index(struct s_stack *tail_a, int argn); //puts numbers onto array and sorts them using bubble sort

//stack utils
struct s_stack	*add_to_empty(int data, int ei); //creates a new node
//struct s_stack	*push_at_beg(struct s_stack *tail, int data, int ei);
struct s_stack	*add_at_beg(struct s_stack *tail, int data, int ei); //adds a new node at the beginning of the stack
struct s_stack	*add_at_end(struct s_stack *tail, int data, int ei); //adds a new node at the end
struct s_stack	*del_first(struct s_stack *tail); //deletes the first node
struct s_stack	*del_last(struct s_stack *tail); //deletes the last node

//sorting functions
void	sa(struct s_stack **tail, char stack_name); //also sb
void	ss(struct s_stack **tail_a, struct s_stack **tail_b); //sa and sb at the same time
void	pa(struct s_stack **tail_b, struct s_stack **tail_a); //takes first element of b and puts it at the top of a
void	pb(struct s_stack **tail_a, struct s_stack **tail_b); //takes first element of a and puts it at the top of b
void	ra(struct s_stack **tail, char stack_name); //also rb
void	rr(struct s_stack **tail_a, struct s_stack **tail_b);
void	rra(struct s_stack **tail, char stack_name); //also rrb
void	rrr(struct s_stack **tail_a, struct s_stack **tail_b);

//mini sort
void	mini_sort(struct s_stack **a, int argn);
void	bi_sort(struct s_stack **tail);
void	tri_sort(struct s_stack **tail);
void	quad_sort(struct s_stack **tail);
void	quint_sort(struct s_stack **tail);
void	sext_sort(struct s_stack **tail);

//multi sort
int		case_counter(int ei, int p, struct s_stack *tail_b);
void	multi_sort(struct s_stack **a, int argn);
void	quicksort(struct s_stack **a, int argn);
void	quickdivision(struct s_stack **a, int argn);


//sorting utils
int		sorted(struct s_stack *tail); //returns TRUE if stack is sorted in ascending order
int		rev_sorted(struct s_stack *tail); //returns TRUE if stack is sorted in descending order
int		getmax(t_stack *tail);
int		getmin(t_stack *tail);
int		find_median(struct s_stack *tail, int argn);

int		is_tri(struct s_stack *tail);


//freeing functions
//void	free_list(struct s_stack *tail) //make sure to free index_offset when the last node is freed

//TO REMOVE
void	print(struct s_stack *tail);
#endif