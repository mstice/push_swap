#include "push_swap.h"

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
