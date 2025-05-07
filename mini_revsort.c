#include "push_swap.h"

void	mini_revsort(t_stack **b, int argn)
{
	if (argn == 2)
		bi_revsort(b);
	else if (argn == 3)
		tri_revsort(b);
	// else if (argn == 4)
	// 	quad_revsort(b);
	// else if (argn == 5)
	// 	quint_revsort(b);
}

void	bi_revsort(t_stack **tail)
{
	t_stack *head;

	if (revsorted(*tail))
		return ;
	head = (*tail)->next;
	if (head->nbr < (*tail)->nbr)
		sa(tail, 'b');
}

void	tri_revsort(t_stack **tail)
{
	int	a;
	int	b;
	int c;

	if (revsorted(*tail)) //3 2 1
		return ;
	a = (*tail)->next->nbr;
	b = (*tail)->next->next->nbr;
	c = (*tail)->nbr;
	if (a < b && a < c && b < c) //1 2 3
		sa(tail, 'b'), rra(tail, 'b');
	else if (a < b && a < c && b > c) //1 3 2
		ra(tail, 'b');
	else if (a > b && a < c) //2 1 3
		rra(tail, 'b');
	else if (a < b && a > c) //2 3 1
		sa(tail, 'b');
	else if (a > b && a > c && b < c) // 3 1 2
		rra(tail, 'b'), sa(tail, 'b');
	if(revsorted(*tail))
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
