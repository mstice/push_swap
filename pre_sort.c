#include "push_swap.h"
void	assign_index(t_stack **tail_a, int *arr, int argn)
{
	t_stack *temp;
	int				i;

	temp = (*tail_a)->next;
	i = 0;
	while (i != argn)
	{
		if (temp -> nbr == arr[i])
		{
			temp -> ei = i + 1;
			i++;
		}
		else
			temp = temp -> next;
	}
	return ;
	printf("stack a:");
	print(*tail_a);
}

void	sort_index(t_stack *tail_a, int argn)//takes stack and puts it into array, and bubble sorts it
{
	int				arr[argn];
	t_stack *temp;
	int				i;
	int				j;
	int				t;
	
	i = 0;
	temp = tail_a->next;
	while (i < argn)
	{
		arr[i] = temp -> nbr;
		temp = temp -> next;
		i++;
	}
	i = 0;
	while (i < argn)
	{
		j = 0;
		while (j < (argn - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
			j++;
		}
		i++;
	}
	//j = 0;
	// printf("arr:");
	// while (j != argn)
	// 	printf("%d ", arr[j++]);
	assign_index(&tail_a, arr, argn);
	// printf("\n");
	// printf("stack a:");
	// print(tail_a);
}
