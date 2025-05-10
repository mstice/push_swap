#include "push_swap.h"

void	mini_revsort(t_stack **b, int size_b)
{
	if (size_b == 2)
		bi_revsort(b);
	else if (size_b == 3)
		tri_revsort(b);
	// else if (argn == 4)
	// 	quad_revsort(b);
	// else if (argn == 5)
	// 	quint_revsort(b);
}

void	bi_revsort(t_stack **b)
{
	t_stack *head;

	if (revsorted(*b))
		return ;
	head = (*b)->next;
	if (head->nbr < (*b)->nbr)
		sa(b, 'b');
}

void	tri_revsort(t_stack **b)
{
	int	w;
	int	x;
	int y;

	if (revsorted(*b)) //3 2 1
		return ;
	w = (*b)->next->nbr;
	x = (*b)->next->next->nbr;
	y = (*b)->nbr;
	if (w < x && w < y && x < y) //1 2 3
		sa(b, 'b'), rra(b, 'b');
	else if (w < x && w < y && x > y) //1 3 2
		ra(b, 'b');
	else if (w > x && w < y) //2 1 3
		rra(b, 'b');
	else if (w < x && w > y) //2 3 1
		sa(b, 'b');
	else if (w > x && w > y && x < y) // 3 1 2
		rra(b, 'b'), sa(b, 'b');
	if(revsorted(*b))
		return ;
	else
		ft_putstr_fd("tri_revsort failed", 2);
}

// void	quad_revsort(t_stack **tail)
// {
// 	int a;
// 	int b;
// 	int c;
// 	int d;

// 	if (revsorted(*tail))
// 		return ;
// 	a = (*tail)->next->nbr;
// 	b = (*tail)->next->next->nbr;
// 	c = (*tail)->prev->nbr;
// 	d = (*tail)->nbr;
// 	if (a < b && a < c && a < d) //if a is 1
// 	{
// 	}
// 	else if ((a < b && a < c && a > d) || (a < b && a > c && a < d) || (a > b && a < c && a < d)) //if a is 2
// 	else if ((a > b && a > c && a < d) || (a > b && a < c && a > d) || (a < b && a > c && a > )) //if a is 3
// 	else if (a > b && b > c && c > d)// if a is 4


// 1,2,4,3
// 1,3,2,4
// 1,3,4,2
// 1,4,2,3
// 1,4,3,2
// 2,1,3,4
// 2,1,4,3
// 2,3,1,4
// 2,3,4,1
// 2,4,1,3
// 2,4,3,1
// 3,1,2,4
// 3,1,4,2
// 3,2,1,4
// 3,2,4,1
// 3,4,1,2
// 3,4,2,1
// 4,1,2,3
// 4,1,3,2
// 4,2,1,3
// 4,2,3,1
// 4,3,1,2
// 4,3,2,1
// }
