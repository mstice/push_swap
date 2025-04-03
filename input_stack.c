#include "push_swap.h"

static long	ft_atol(const char *nptr)
{
	long	i;
	long	number;
	long	sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0')
	{
		if ((nptr[i] >= '0' && nptr[i] <= '9'))
			number = number * 10 + (nptr[i] - '0');
		else
			break ;
		i++;
	}
	return (number * sign);
}

void	input_stack(int argc, char **argv)
{
	struct s_stack	*a;
	struct s_stack	*head;
	struct s_stack	*temp;
	int				j;
	long			n;

	printf("stack a: ");
	a = NULL;
	j = 1;
	if (argc == 2)
		j = 0;
	while (argv[j] != NULL)
	{
		n = ft_atol(argv[j++]);
		if (n > INT_MAX || n < INT_MIN)
			ft_error();
		a = add_at_end(a, n);
		printf("%d ", a -> nbr);
	}
	printf("\na is this %d", a -> nbr);
	head = a;
	while (head->next != a)  // Loop through each node
	{
		temp = head->next;  // Start checking from the next node
		while (temp != a)   // Ensure we don't compare beyond the circular list
		{
			if (head->nbr == temp->nbr)
				ft_error();
			temp = temp->next;
		}
		head = head->next;
	}
 	printf("\nsorted: %d \n", sorted(a));
}