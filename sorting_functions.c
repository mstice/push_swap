#include "push_swap.h"

void	sa(struct s_stack **tail, char stack_name) //adapted to ei
{
	int data1;
	int data2;
	int ei1;
	int ei2;
   
	// if (sorted(*tail) == 1)
	// 	return ;
	data1 = (*tail) -> next -> nbr;
	ei1 = (*tail) -> next -> ei;
	data2 = (*tail) -> next -> next -> nbr;
	ei2 = (*tail) -> next -> next -> ei;
	(*tail) -> next -> nbr = data2;
	(*tail) -> next -> ei = ei2;
	(*tail) -> next -> next -> nbr = data1;
	(*tail) -> next -> next -> ei = ei1;
	if (stack_name == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("sb\n", 1);
	else if (stack_name != 'a' && stack_name != 'b' && stack_name != 's')
		ft_putstr_fd("Wrong stack name!", 1) , ft_error();
	return ;
}

void	ss(struct s_stack **tail_a, struct s_stack **tail_b)
{
	sa(tail_a, 's');
	sa(tail_b, 's');
	ft_putstr_fd("ss\n", 1);
	return ;
}

void	pa(struct s_stack **tail_b, struct s_stack **tail_a) //takes first element of b and puts it at the top of a
{
	struct s_stack	*head_b;

	if (!tail_b || !*tail_b || !(*tail_b)->next)
		return ;
	head_b = (*tail_b)->next;
	if (*tail_a == NULL)
		(*tail_a) = add_to_empty(head_b->nbr, head_b->ei);
	else
		(*tail_a) = add_at_beg(*tail_a, head_b->nbr, head_b->ei);
	*tail_b = del_first(*tail_b);
	// if (*tail_b == NULL)
	// 	free(*tail_b); //maybe this will cause problems haha
	ft_putstr_fd("pa\n", 1);
	return ;
}

void	pb(struct s_stack **tail_a, struct s_stack **tail_b) //takes first element of a and puts it at the top of b
{
	struct s_stack	*head_a;

	if (!tail_a || !*tail_a || !(*tail_a)->next)
		return ;
	head_a = (*tail_a)->next;
	if (*tail_b == NULL)
		(*tail_b) = add_to_empty(head_a->nbr, head_a->ei);
	else
		(*tail_b) = add_at_beg(*tail_b, head_a->nbr, head_a->ei);
	*tail_a = del_first(*tail_a);
	// if (*tail_a == NULL)
	// 	free(*tail_a); //maybe this will cause problems
	ft_putstr_fd("pb\n", 1);
	return ;
}

void	ra(struct s_stack **tail, char stack_name) //adapted to ei
{
	int data1;
	int ei1;

	// if (sorted(*tail) == 1)
	// 	return ;
	data1 = (*tail)->next->nbr;
	ei1 = (*tail)->next->ei;
	*tail = del_first(*tail);
	*tail = add_at_end(*tail, data1, ei1);
	// printf("ra:");
	// print(tail);
	if (stack_name == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("rb\n", 1);
	else if (stack_name != 'a' && stack_name != 'b' && stack_name != 'r')
		ft_putstr_fd("Wrong stack name!", 1), ft_error();
	return ;
}

void	rr(struct s_stack **tail_a, struct s_stack **tail_b)
{
	ra(tail_a, 'r');
	ra(tail_b, 'r');
	ft_putstr_fd("rr\n", 1);
	return ;
}

void	rra(struct s_stack **tail, char stack_name) //adapted to ei
{
	int	data1;
	int ei1;

	// if (sorted(*tail) == 1)
	// 	return ;
	data1 = (*tail)->nbr;
	ei1 = (*tail)->ei;
	*tail = del_last(*tail);
	*tail = add_at_beg(*tail, data1, ei1);
	// printf("rra:");
	// print(tail);
	if (stack_name == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (stack_name == 'b')
		ft_putstr_fd("rrb\n", 1);
	else if (stack_name != 'a' && stack_name != 'b' && stack_name != 'r')
		ft_putstr_fd("Wrong stack name!", 1), ft_error();
	return ;
}

void	rrr(struct s_stack **tail_a, struct s_stack **tail_b)
{
	rra(tail_a, 'r');
	rra(tail_b, 'r');
	ft_putstr_fd("rrr\n", 1);
	return ;
}

