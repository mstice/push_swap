#include "push_swap.h"

void sa(struct s_stack *tail, char stack_name)
{
	int data1;
	int data2;
   
	data1 = tail -> next -> nbr;
	data2 = tail -> next -> next -> nbr;
	tail -> next -> nbr = data2;
	tail -> next -> next -> nbr = data1;
	// printf("sa:");
	// print(tail);
	if (stack_name == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("sb\n", 1);
	else if (stack_name == 's')
		return ;
	else
		ft_error();
}

void	ss(struct s_stack *tail_a, struct s_stack *tail_b)
{
	sa(tail_a, 's');
	sa(tail_b, 's');
	ft_putstr_fd("ss\n", 1);
}

void	ra(struct s_stack *tail, char stack_name)
{
	int data;

	data = tail -> next -> nbr;
	tail = del_first(tail);
	tail = add_at_end(tail, data);
	//printf("ra:");
	//print(tail);
	if (stack_name == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("rb\n", 1);
	else if (stack_name == 'r')
		return;
	else
		ft_error();
}

void	rr(struct s_stack *tail_a, struct s_stack *tail_b)
{
	ra(tail_a, 'r');
	ra(tail_b, 'r');
	ft_putstr_fd("rr\n", 1);
}


void	rra(struct s_stack *tail, char stack_name) //NOT CORRECT
{
	int	data;

	data = tail -> nbr;
	tail = del_last(tail);
	tail = add_at_beg(tail, data);
	// printf("rra:");
	// print(tail);
	if (stack_name == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("rrb\n", 1);
	else if (stack_name == 'r')
		return ;
	else
		ft_error();
}

void	rrr(struct s_stack *tail_a, struct s_stack *tail_b)
{
	rra(tail_a, 'r');
	rra(tail_b, 'r');
	ft_putstr_fd("rrr\n", 1);
}

