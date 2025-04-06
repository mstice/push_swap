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
}				t_stack;

//checking the input is valid and processing the input
void	ft_error(void);
char	**input_check(int argc, char **argv); //checks for non-numbers
void	input_stack(int argc, char **argv); //checks for ints, deletes zeroes and doubles

//stack utils
struct s_stack	*add_to_empty(int data); //creates a new node
struct s_stack	*add_at_beg(struct s_stack *tail, int data); //adds a new node at the beginning of the stack
struct s_stack	*add_at_end(struct s_stack *tail, int data); //adds a new node at the end
struct s_stack	*del_first(struct s_stack *tail); //deletes the first node
struct s_stack	*del_last(struct s_stack *tail); //deletes the last node

// //mini sort
// void	bi_sort(t_stack stack, char **argv);
// void	tri_sort(t_stack stack, char **argv);
// void	quad_sort(t_stack stack, char **argv);
// void	quint_sort(t_stack stack, char **argv);

// //multi sort
// void	multi_sort(t_stack stack, char **argv);

//sorting functions
void	sa(struct s_stack *tail, char stack_name); //also sb
void	ss(struct s_stack *tail_a, struct s_stack *tail_b);
// void	pa(t_stack stack);
// void	pb(t_stack stack);
void	ra(struct s_stack *tail, char stack_name); //also rb
void	rr(struct s_stack *tail_a, struct s_stack *tail_b);
void	rra(struct s_stack *tail, char stack_name); //also rrb
void	rrr(struct s_stack *tail_a, struct s_stack *tail_b);

//sorting utils
bool	sorted(struct s_stack *tail); //returns TRUE if stack is sorted in ascending order
// int		big(t_stack stack); //finds the position of the biggest number
// int		smol(t_stack stack); //finds the position of the smallest number

//TO REMOVE
void	print(struct s_stack *tail);
#endif