#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //remove
#include <ctype.h> //remove
#include <string.h> //remove

// typedef struct	s_list
// {
// 	int				data;
// 	struct s_list	*link;
// }				t_stacka;

// typedef struct	s_list
// {
// 	int				data;
// 	struct s_list	*link;
// }				t_stackb;


//checking the input is valid
void	input_check(int argc, char **argv);
void	input_atoi(char **argv);

#endif