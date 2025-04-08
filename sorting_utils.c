#include "push_swap.h"

int	sorted(struct s_stack *tail)
{
	struct s_stack *head;

	head = tail -> next;
	
	while ((head != tail) && head -> nbr < head -> next -> nbr)
		head = head -> next;
	if (head == tail)
		return (1);
	else //if (head != tail && head -> nbr >= head -> next -> nbr)
		return (0);
}

void	assign_index(struct s_stack **tail_a, int *arr, int argn)
{
	struct s_stack *temp;
	int				i;

	temp = (*tail_a)->next;
	i = 0;
	while (i != argn)
	{
		if (temp -> nbr == arr[i])
		{
			temp -> index = i + 1;
			i++;
		}
		else
			temp = temp -> next;
	}
	return ;
	printf("stack a:");
	print(*tail_a);
}

void	sort_index(struct s_stack *tail_a, int argn)//takes stack and puts it into array, and bubble sorts it
{
	int				arr[argn];
	struct s_stack *temp;
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
	j = 0;
	printf("arr:");
	while (j != argn)
		printf("%d ", arr[j++]);
	assign_index(&tail_a, arr, argn);
	printf("\n");
	printf("stack a:");
	print(tail_a);
}


int	big(t_stack *tail)
{
	t_stack	*temp;
	int		big;

	temp = tail -> next;
	big = temp -> nbr;
	temp = temp -> next;
	while (temp != tail)
	{
		if(temp -> nbr > big)
			big = temp -> nbr;
		temp = temp -> next;
	}
	return (big);
}