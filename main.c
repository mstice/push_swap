/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtice <mtice@student.42london.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:09:16 by mtice             #+#    #+#             */
/*   Updated: 2025/05/16 14:13:36 by mtice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack **tail, int stack_size)
{
	while (stack_size--)
		del_first(*tail);
}

static void	init(t_info *info)
{
	info->small = 0;
	info->big = 0;
	info->pivot = 0;
	info->first = 0;
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	char			**strs;
	int				argn;
	struct s_stack	*a;
	struct s_stack	*b;
	t_info			info;

	a = NULL;
	b = NULL;
	init(&info);
	if (argc == 1)
		exit(1);
	strs = input_check(argc, argv);
	argn = argc_counter(strs);
	a = input_stack(argn, strs);
	if (sorted(a))
		return (free_list(&a, argn), 0);
	sort_index(a, argn);
	if (argn > 1 && argn <= 5)
		mini_sort(&a, &b, argn);
	else if (argn > 5 && argn <= 500)
		quicksort_a(&a, &b, info, argn);
	free_list(&a, stack_size(a));
	free_list(&b, stack_size(b));
	return (0);
}
