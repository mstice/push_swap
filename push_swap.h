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
	int				index; //expected index
}				t_stack;

//checking the input is valid and processing the input
void			ft_error(void);
char			**input_check(int argc, char **argv); //checks for non-numbers
struct s_stack	*input_stack(int argc, char **argv); //checks for ints, deletes zeroes and doubles
int				argc_counter(char **strs); //counts argcs, which needs to happen when input is a string

//stack utils
struct s_stack	*add_to_empty(int data); //creates a new node
struct s_stack	*add_at_beg(struct s_stack *tail, int data); //adds a new node at the beginning of the stack
struct s_stack	*add_at_end(struct s_stack *tail, int data); //adds a new node at the end
struct s_stack	*del_first(struct s_stack *tail); //deletes the first node
struct s_stack	*del_last(struct s_stack *tail); //deletes the last node

// //mini sort
void	mini_sort(struct s_stack **tail, int argn);
void	bi_sort(struct s_stack **tail);
void	tri_sort(struct s_stack **tail);
void	quad_sort(struct s_stack **tail);
void	quint_sort(struct s_stack **tail);

// //multi sort
// void	multi_sort(t_stack stack, char **argv);

//sorting functions
void	sa(struct s_stack **tail, char stack_name); //also sb
void	ss(struct s_stack **tail_a, struct s_stack **tail_b);
void	pa(struct s_stack **tail_b, struct s_stack **tail_a); //takes first element of b and puts it at the top of a
void	pb(struct s_stack **tail_a, struct s_stack **tail_b); //takes first element of a and puts it at the top of b
void	ra(struct s_stack **tail, char stack_name); //also rb
void	rr(struct s_stack **tail_a, struct s_stack **tail_b);
void	rra(struct s_stack **tail, char stack_name); //also rrb
void	rrr(struct s_stack **tail_a, struct s_stack **tail_b);

//sorting utils
int		sorted(struct s_stack *tail); //returns TRUE if stack is sorted in ascending order
// int		big(t_stack stack); //finds the position of the biggest number
// int		smol(t_stack stack); //finds the position of the smallest number
void	assign_index(struct s_stack **tail_a, int *arr, int argn); //updates expected index onto each node based on sorted array
void	sort_index(struct s_stack *tail_a, int argn); //puts numbers onto array and sorts them using bubble sort

//freeing functions
//void	free_list(struct s_stack *tail) //make sure to free index_offset when the last node is freed

//TO REMOVE
void	print(struct s_stack *tail);
#endif