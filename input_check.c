#include "push_swap.h"
static char	**input_string(char **argv)
{
	int	j;

	argv = ft_split(argv[1], ' ');
	j = 0;
	while (argv[j] != NULL)
		printf("%s\n", argv[j++]);
	return (argv);
}

void input_check(int argc, char **argv)
{
	int	i;
	int j;

	
	i = 0;
	j = 1;
	if (argc == 2) //DO SOMETHING
	{
		argv = input_string(argv);
		j = 0;
	}
	while (argv[j] != NULL) //checks for non-numbers
	{
 		if((argv[j][i] == '+' || argv[j][i] == '-') && i == 0) //allows for + and -
 			i++;
 		while (argv[j][i] != '\0') //checks for non-numbers
 		{
 			if (ft_isdigit(argv[j][i]) == 0)
 				ft_error();
 			i++;
 		}
 		i = 0;
 		j++;
 	}
}
