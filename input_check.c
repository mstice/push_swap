#include "push_swap.h"
#include "libft/libft.h"

void input_check(int argc, char **argv)
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 1;
	while (argv[j] != NULL) //checks for non-numbers
	{
		if((argv[j][i] == '+' || argv[j][i] == '-') && i == 0) //allows for + and -
			i++;
		while (argv[j][i] != '\0') //checks for non-numbers
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				write(2, "Error\n", 6), exit(1);
			i++;
		}
		i = 0;
		j++;
	}
	j = 1;
	while (argv[j] != NULL) //checks for repeated numbers and zeroes to the left
	{
		k = j + 1;
		while (argv[k] != NULL)
		{
			i = 0;
			while (argv[j][i] == '0')
			{
				argv[j]++, i++;
			}
			i = 0;
			while (argv[k][i] == '0')
				argv[k]++, i++;
			if (ft_strncmp(argv[j], argv[k], argc - 1) != 0) //use ft version here
				k++;
			else
				write(2, "Error\n", 6), exit(1);
		}
		if (argv[k] == NULL)
			j++;
	}
}

// void input_atoi(char **argv) //should return t_stacka
// {
// 	int	j;

// 	j = 1;
	
// }