/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:54:07 by asebrani          #+#    #+#             */
/*   Updated: 2024/05/22 16:46:17 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_stack(t_stack **a, char **av)
{
	char	*str;
	char	**args;

	str = join_it(av);
	if (!str)
		return (0);
	args = split(str, ' ');
	free(str);
	if (!args)
		return (0);
	stack_init(a, args);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!initialize_stack(&a, av + 1))
		return (0);
	if (sorted_or_no(a) == 1)
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	return (free_stack(&a), 0);
}
