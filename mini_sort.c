#include "push_swap.h"

void	mini_sort(t_stack **a, t_stack **b, int size_a)
{
	if (size_a == 2)
		bi_sort(a);
	else if (size_a == 3)
		tri_sort(a);
	else if (size_a == 4)
		quad_sort(a, b);
	else if (size_a == 5)
		quint_sort(a, b);
	// else if (argn == 6)
	// 	sext_sort(a);
}

void	bi_sort(t_stack **a)
{
	t_stack *head;

	if (sorted(*a))
		return ;
	head = (*a) -> next;
	if (head->nbr > (*a)->nbr)
		sa(a, 'a');
	return ;
}

void	tri_sort(t_stack **a)
{
	int	w;
	int x;
	int y;

	if (sorted(*a)) //123
		return ;
	w = (*a) -> next -> nbr;
	x = (*a) -> next -> next -> nbr;
	y = (*a) -> nbr;
	if (w < x && w < y && x > y) //1 3 2
		rra(a, 'a'), sa(a, 'a');
	else if (w > x && w < y) // 2 1 3
		sa(a, 'a');
	else if (w < x && w > y) // 2 3 1
		rra(a, 'a');
	else if (w > x && w > y && x < y) //3 1 2
		ra(a, 'a');
	else if (w > x && w > y && x > y) // 3 2 1
		sa(a, 'a'), rra(a, 'a');
	else
		ft_putstr_fd("tri_sort failed", 2), ft_error();
	if (sorted(*a))
		return ;
}

void	quad_sort(t_stack **a, t_stack **b)
{
	int		w;
	int		x;
	int		y;
	int		z;

	if (sorted(*a))
		return ;
	w = (*a)->next->nbr;
	x = (*a)->next->next->nbr;
	y = (*a)->prev->nbr;
	z = (*a)->nbr;
	pb(a, b);
	tri_sort(a);
	pa(b, a);
	if (w < x && w < y && w < z) //if w is 1
		return ;
	else if ((w < x && w < y && w > z) || (w < x && w > y && w < z) || (w > x && w < y && w < z))
		sa(a, 'a');
	else if ((w > x && w > y && w < z) || (w > x && w < y && w > z) || (w < x && w > y && w > z))
		rra(a, 'a'), sa(a, 'a'), ra(a, 'a'), ra(a, 'a');
	else if (w > x && w > y && w > z)
		ra(a, 'a');
	if (sorted(*a))
		return ;
}

void	quint_sort(t_stack **a, t_stack **b) //here should be stack b and stack a
{
	int	pushed;
	int	pivot;

	if (sorted(*a))
		return ;
	pushed = 0;
	pivot = find_median(*a, 5);
	while (pushed != 2)
	{
		if ((*a)->next->ei < pivot)
			pb(a, b), pushed++;
		else
			ra(a, 'a');
	}
	tri_sort(a);
	if ((*b)->next->ei < (*b)->next->next->ei)
		sa(b, 'b');
	pa(b, a), pa(b, a);
	if (sorted(*a))
		return;
	else
		ft_putstr_fd("quint sort failed", 2), free_list(a, stack_size(*a)), ft_error();
	return ;
}

// void	sext_sort(t_stack **tail)
// {
// 	t_stack *b = NULL;
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