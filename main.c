#include "push_swap.h"

//CHECKLIST
//make sure to check sorted function thoroughly
//make sure to check for double numbers

void 	ft_error(void)
{
	write(2, "Error\n", 6), exit(1);
}


int	main(int argc, char **argv)
{
	// int	j;
	
	if (argc == 1)
		exit(1);
	//if (argc == 2)
		//will still have to process this
	input_check(argc, argv);
	input_stack(argc, argv);
	// if (argc == 3)
	// 	bi_sort();
	// else if (argc == 4)
	// 	tri_sort();
	// else if (argc == 5)
	// 	quad_sort();
	// else if (argc == 6)
	// 	quint_sort();
	// else
	// 	multi_sort();
	// j = 1;
	// printf("ARGV: ");
	// while (argv[j] != NULL)
	// 	printf("%s ", argv[j++]);
	printf("\n");

	//free all nodes
	return(0);
}