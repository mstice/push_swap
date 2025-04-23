#include "push_swap.h"

//CHECKLIST
//make sure to check sorted function thoroughly
//make sure to check for double numbers

void 	ft_error(void)
{
	write(2, "Error\n", 6), exit(1);
}

// int	main(int argc, char **argv)
// {
// 	char	**strs;
// 	int		argn;
// 	struct s_stack *a = NULL;
	
// 	if (argc == 1)
// 		exit(1);
// 	strs = input_check(argc, argv);
// 	argn = argc_counter(strs);
// 	a = input_stack(argn, strs);
// 	if (sorted(a))
// 		ft_putstr_fd("Numbers are already sorted!", 1), exit(0);
// 	sort_index(a, argn);
// 	//printf("stack a: "), print(a);
// 	if (argn > 1 && argn <= 5)
// 		mini_sort(&a, argn);
// 	// else if (argn >= 5 && argn <= 500)
// 	// 	multi_sort(&a, argn);
// 	if (argn > 500)
// 		ft_putstr_fd("Can't deal with this!", 1), exit(1);
// 	//printf("new stack a:"), print(a);
// 	free(a);
// 	return(0);
// }