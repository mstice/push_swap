#include "push_swap.h"

//CHECKLIST

void	free_list(t_stack **tail, int stack_size)
{
	while (stack_size--)
		del_first(*tail);
}


void 	ft_error(void)
{
	ft_putstr_fd("Error\n", 2), exit(1);
}

int	main(int argc, char **argv)
{
	char	**strs;
	int		argn;
	struct s_stack *a = NULL;
	struct s_stack *b = NULL;
	
	if (argc == 1)
		exit(1);
	strs = input_check(argc, argv);
	argn = argc_counter(strs);
	a = input_stack(argn, strs);
	if (sorted(a))
		ft_putstr_fd("Numbers are already sorted!\n", 2), free_list(&a, argn), ft_error();
	sort_index(a, argn);
	//printf("stack a: "), print(a);
	//printf("stack a size: %d stack b size: %d\n", stack_size(a), stack_size(b));
	if (argn > 1 && argn <= 5)
		mini_sort(&a, &b, argn);
	if (argn > 5 && argn <= 500)
		quicksort_a(&a, &b, argn);
	if (argn > 500)
		ft_putstr_fd("Max number of inputs is 500!\n", 2), free_list(&a, argn), ft_error();
	//printf("new stack a:"), print(a);
	if (b != NULL)
		printf("new stack b:"), print(b);
	free_list(&a, argn);
	return(0);
}