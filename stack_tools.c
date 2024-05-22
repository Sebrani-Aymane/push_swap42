/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:15:32 by asebrani          #+#    #+#             */
/*   Updated: 2024/04/25 00:19:30 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	create_node(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->nbr = value;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
	node->target_node = NULL;
}

t_stack	*find_smallest(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < smallest)
		{
			smallest_node = stack;
			smallest = stack->nbr;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest_target == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		count ++;
		stack = stack->next;
	}
	return (count);
}
