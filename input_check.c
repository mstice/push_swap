#include "push_swap.h"

//checks for non-numbers and splits the argv into separate strings each containing the inputs
char **input_check(int argc, char **argv)
{
	int	i;
	int j;
	char **strs;

	j = 0;
	if (argc == 2) //DO SOMETHING
		strs = ft_split(argv[1] , ' ');
	else
		strs = &argv[1];
	while (strs[j] != NULL) //checks for non-numbers
	{
		i = 0;
 		if((strs[j][i] == '+' || strs[j][i] == '-') && i == 0) //allows for + and -
 			i++;
 		while (strs[j][i] != '\0') //checks for non-numbers
 		{
 			if (ft_isdigit(strs[j][i]) == 0)
 				ft_error();
 			i++;
 		}
 		j++;
 	}
	return (strs);
}

//counts the number of arguments after ft_split
int	argc_counter(char **strs)
{
	int	j;

	j = 0;
	while (strs[j] != NULL)
		j++;
	return (j);
}

//supporting function for input_stack
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

//converts the inputs passed as strings to numbers and checks for double numbers, processes minus and plusses
t_stack *input_stack(int argn, char **argv)
{
	t_stack	*a;
	t_stack	*head;
	t_stack	*temp;
	int		j;
	long	n;

	a = NULL;
	j = 0;
	if (argn == 0)
		ft_error();
	while (argv[j] != NULL)
	{
		n = ft_atol(argv[j++]);
		if (n > INT_MAX || n < INT_MIN)
			free_list(&a, stack_size(a)), ft_error();
		a = add_at_end(a, n, 0);
	}
	head = a;
	while (head->next != a)
	{
		temp = head->next;
		while (temp != a)
		{
			if (head->nbr == temp->nbr)
				free_list(&a, stack_size(a)), ft_error();
			temp = temp->next;
		}
		head = head->next;
	}
	return(a);
}