#include "push_swap.h"
//#include "libft/libft.h"

//CHECKLIST
//change all functions to ones of Libft
//figure out how to include Libft using makefile

int	main(int argc, char **argv)
{
	int	j;
	
	if (argc <= 1)
		write(2, "Error\n", 6), exit(1);
	input_check(argc, argv);
	// input_atoi(argv);
	// while (argv[j] != NULL)
	// {
	// 	if((argv[j][i] == '+' || argv[j][i] == '-') && i == 0) //allows for + and -
	// 		i++;
	// 	while (argv[j][i] != '\0') //checks for non-numbers
	// 	{
	// 		if (argv[j][i] < '0' || argv[j][i] > '9')
	// 			write(2, "Error\n", 6), exit(1);
	// 		i++;
	// 	}
	// 	i = 0;
	// 	j++;
	// }
	// j = 1;
	// while (argv[j] != NULL)
	// {
	// 	k = j + 1;
	// 	while (argv[k] != NULL && strcmp(argv[j], argv[k]) != 0)
	// 		k++;
	// 	if (argv[k] != NULL && strcmp(argv[j], argv[k]) == 0)
	// 		write(2, "Error\n", 6), exit(1);
	// 	else if (argv[k] == NULL)
	// 		j++;
	// }
	j = 1;
	while (argv[j] != NULL)
		printf("%s ", argv[j++]);
	return(0);
}