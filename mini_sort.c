#include "push_swap.h"

void	mini_sort(struct s_stack **a, int argn)
{
	if (argn == 2)
		bi_sort(a);
	else if (argn == 3)
		tri_sort(a);
	else if (argn == 4)
		quad_sort(a);
	else if (argn == 5)
		quint_sort(a);
	// else if (argn == 6)
	// 	sext_sort(a);
}

void	bi_sort(struct s_stack **tail)
{
	struct s_stack *head;

	if (sorted(*tail))
		return ;
	head = (*tail) -> next;
	if (head->nbr > (*tail)->nbr)
		sa(tail, 'a');
	return ;
}

void	tri_sort(struct s_stack **tail)
{
	int	a;
	int b;
	int c;

	if (sorted(*tail)) //123
		return ;
	a = (*tail) -> next -> nbr;
	b = (*tail) -> next -> next -> nbr;
	c = (*tail) -> nbr;
	if (a < b && a < c && b > c)
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
	if (sorted(*tail))
		return ;
}

void	quad_sort(struct s_stack **tail)
{
	struct s_stack *tail_b;
	int		a;
	int		b;
	int		c;
	int		d;

	if (sorted(*tail))
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
	if (sorted(*tail))
		return ;
}

void	quint_sort(struct s_stack **tail)
{
	struct s_stack *b = NULL;
	int				n;
	int				median;

	if (sorted(*tail))
		return ;
	n = 5;
	median = n/2;
	while (n > (median + 1)) //if odd number, has to be median + 1
	{
		if ((*tail)->next->ei <= median) //can do some more optimisation here
			pb(tail, &b), n--;
		else
			ra(tail, 'a');
	}
	tri_sort(tail);
	if (sorted(b))
		sa(&b, 'b');
	while (n < 5)
	{
		if ((*tail)->next->ei - b->next->ei == 1)
			pa(&b, tail), n++;
		else
			ra(tail, 'a');
	}
	if (sorted(*tail))
		return ;
	else
		ft_putstr_fd("quint sort failed", 1);
	return ;
}

// void	sext_sort(struct s_stack **tail)
// {
// 	struct s_stack *b = NULL;
// 	int				n;
// 	int				median;
// 	if (sorted(*tail))
// 		return ;
// 	n = 6;
// 	median = find_median(*tail, n);
// 	while (n >= median) //if even number, has to be n >= median
// 	{
// 		if ((*tail)->next->ei <= median)
// 			pb(tail, &b), n--;
// 		else
// 			ra(tail, 'a');
// 	}
// 	tri_sort(tail), tri_sort(&b), sa(&b, 'b'), ra(&b, 'b');
// 	while (n < 6)
// 	{
// 		if ((*tail)->next->ei - b->next->ei == 1)
// 			pa(&b, tail), n++;
// 		else
// 			ra(tail, 'a');
// 	}
// 	if (sorted(*tail))
// 		return ;
// 	else
// 		ft_putstr_fd("sext sort failed", 1);
// 	return ;
// }