/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:55:06 by asebrani          #+#    #+#             */
/*   Updated: 2024/05/07 18:11:10 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_or_no(t_stack *stack)
{
	if (NULL == stack)
		return (0);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (1);
		stack = stack->next;
	}
	return (2);
}

static	t_stack	*highest(t_stack *stack)
{
	long	highest;
	t_stack	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->nbr > highest)
		{
			highest = stack->nbr;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_three(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		init_node(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a);
	}
}
