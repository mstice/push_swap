#include "push_swap.h"

void	mini_sort(struct s_stack **tail, int argn)
{
	if (argn == 2)
		bi_sort(a);
	else if (argn == 3)
		tri_sort(a);
	else if (argn == 4)
		quad_sort(a);
	else if (argn == 5)
		quint_sort(a);
}

void	bi_sort(struct s_stack **tail)
{
	struct s_stack *head;

	head = (*tail) -> next;
	if (head -> nbr > (*tail) -> nbr)
		sa(tail, 'a');
	return ;
}

void	tri_sort(struct s_stack **tail)
{
	int	a;
	int b;
	int c;

	a = (*tail) -> next -> nbr;
	b = (*tail) -> next -> next -> nbr;
	c = (*tail) -> nbr;
	if (sorted(*tail) == 1) //123
		return ;
	else if (a < b && a < c && b > c)
		rra(tail, 'a'), sa(tail, 'a');
	else if (a > b && a < c)
		sa(tail, 'a');
	else if (a < b && a > c)
		rra(tail, 'a');
	else if (a > b && a > c && b < c)
		ra(tail, 'a');
	else if (a > b && a > c && b > c)
		sa(tail, 'a'), rra(tail, 'a');
	else
		ft_error();
	return ;
}

void	quad_sort(struct s_stack **tail)
{
	struct s_stack *tail_b;
	int		a;
	int		b;
	int		c;
	int		d;

	if (sorted(*tail) == 1)
		return ;
	tail_b = NULL;
	a = (*tail)->next->nbr;
	b = (*tail)->next->next->nbr;
	c = (*tail)->prev->nbr;
	d = (*tail)->nbr;
	pb(tail, &tail_b);
	tri_sort(tail);
	pa(&tail_b, tail);
	if (a < b && a < c && a < d)
		return ;
	else if ((a < b && a < c && a > d) || (a < b && a > c && a < d) || (a > b && a < c && a < d))
		sa(tail, 'a');
	else if ((a > b && a > c && a < d) || (a > b && a < c && a > d) || (a < b && a > c && a > d))
		rra(tail, 'a'), sa(tail, 'a'), ra(tail, 'a'), ra(tail, 'a');
	else if (a > b && a > c && a > d)
		ra(tail, 'a');
	if (sorted(*tail) == 1)
		return ;
}

// void	quint_sort(struct s_stack **tail)
// {
// 	struct s_stack *b;
// 	int		diff = 0;

// 	if (sorted(*tail) == 1)
// 		return ;
// 	b = NULL;
// 	pb(tail, &b);
// 	printf("stack b:"), print(b);
// 	quad_sort(tail);
// 	pa(&b, tail);
// 	while (n != argn)
// 	{
// 		head_a = (*tail)->next->nbr;
// 		head_b = b->next->nbr;
// 		if (head_a > head_b && n != argn)
// 			pa(&b, tail), n++;
// 		head_a = (*tail)->next->nbr;
// 		head_b = b->next->nbr;
// 		if (head_a < head_b && n != argn)
// 		{
// 			ra(tail, 'a');
// 			//printf("Hello");
// 		}
// 		if (n == argn)
// 			break ;
// 	}
// 	if (sorted(*tail) == 1)
// 		return ;
// }



// static void	update_abcd(struct s_stack **tail, struct s_stack **a,	struct s_stack **b, struct s_stack **c, struct s_stack **d)
// {
// 	*a = (*tail)->next;
// 	*b = (*tail)->next->next;
// 	*d = (*tail)->prev;
// 	*c = (*tail)->prev->prev;
// }

// void quad_sort(struct s_stack **tail)
// {

// 	if (sorted(*tail) == 1)
// 		ft_putstr_fd("Numbers are already sorted!\n", 1), return ;
// 	if ((*tail)->next->nbr > (*tail)->next->next->nbr && !sorted(*tail)) //a > b
// 		sa(tail, 'a');
// 	while((*tail)->next->nbr > (*tail)->nbr && !sorted(*tail)) // a > d
// 		rra(tail, 'a');
// 	if ((*tail)->next->nbr > (*tail)->next->next->nbr && !sorted(*tail)) //a > b
// 		sa(tail, 'a');
// 	if ((*tail)->next->next->nbr < (*tail)->prev->nbr && !sorted(*tail)) // b < c
// 	{
// 		if (a < b && c > d)
// 			rra(tail, 'a'), rra(tail, 'a'), sa(tail, 'a'), ra(tail, 'a'), ra(tail, 'a');
// 		else if (a < b && c < d)
// 			sa(tail, 'a'), rra(tail, 'a'), sa(tail, 'a'), rra(tail, 'a'), rra(tail, 'a');
// 	}
// 	else if ((*tail)->next->next->nbr > (*tail)->prev->nbr && !sorted(*tail)) // b > c
// 	{
// 		if(a < b && c < d)
// 		else if (a < b)
// 		else if (c < d)
// 	}
// }

// void	quad_sort(struct s_stack **tail)
// {
// 	struct s_stack *a;
// 	struct s_stack *b;
// 	struct s_stack *c;
// 	struct s_stack *d;

// 	update_abcd(tail, &a, &b, &c, &d);
// 	if (sorted(*tail) == 1)
// 	{
// 		ft_putstr_fd("Numbers are already sorted!\n", 1);
// 		return ;
// 	}
// 	if (a -> nbr > b -> nbr && sorted(*tail) != 1)
// 		sa(tail, 'a'), 	update_abcd(tail, &a, &b, &c, &d);
// 	if (sorted(*tail) != 1)
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 	if (sorted(*tail) != 1)
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 	if (a -> nbr > b -> nbr && sorted(*tail) != 1)
// 		sa(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 	if (a -> nbr < c -> nbr && sorted(*tail) != 1) //1 is at the top
// 	{
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		sa(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		ra(tail,'a'), update_abcd(tail, &a, &b, &c, &d);
// 		ra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		ra(tail,'a'), update_abcd(tail, &a, &b, &c, &d);
// 		if (a -> nbr > b -> nbr && sorted(*tail) != 1)
// 			sa(tail, 'a'), 	update_abcd(tail, &a, &b, &c, &d);		;
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		if (a -> nbr > b -> nbr && sorted(*tail) != 1)
// 			sa(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 	}
// 	if (a -> nbr > c -> nbr && sorted(*tail) != 1) //1 is at the top
// 	{
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		sa(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		ra(tail,'a'), update_abcd(tail, &a, &b, &c, &d);
// 		ra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		ra(tail,'a'), update_abcd(tail, &a, &b, &c, &d);
// 	}
// 	//if 1 before, do original checks
// 	//if 2 before, 
// 	if (a -> nbr > b -> nbr && sorted(*tail) != 1)
// 	{
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 	}
// 	if (a -> nbr > b -> nbr && sorted (*tail) != 1)
// 		sa(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 	if (c -> nbr > d -> nbr && sorted(*tail) != 1) // before c
// 	{
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		rra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		sa(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		ra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 		ra(tail, 'a'), update_abcd(tail, &a, &b, &c, &d);
// 	}
// 	if (sorted(*tail) == 1)
// 		return ;
// }

// //2 3 1 4
// //3 2 1 4

