/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:55:00 by asebrani          #+#    #+#             */
/*   Updated: 2024/04/24 23:58:32 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*curr_a;
	long	target_value;

	while (b)
	{
		target_node = NULL;
		curr_a = a;
		target_value = LONG_MAX;
		while (curr_a)
		{
			if (b->nbr < curr_a->nbr && curr_a->nbr < target_value)
			{
				target_value = curr_a->nbr;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (target_node == NULL)
			target_node = find_smallest(a);
		if (b != NULL)
			b->target_node = target_node;
		b = b->next;
	}
}

void	current_index(t_stack *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (NULL == stack)
		return ;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->over_mid = 1;
		else
			stack->over_mid = 0;
		stack = stack->next;
		++i;
	}
}

void	get_cheapest_to_push(t_stack *b)
{
	long	target_value;
	t_stack	*target_node;

	target_node = NULL;
	if (b == NULL)
		return ;
	target_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < target_value)
		{
			target_value = b->push_price;
			target_node = b;
		}
		b = b->next;
	}
	target_node->cheapest_target = 1;
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		if (b->over_mid == 1)
			b->push_price = b->index;
		else
			b->push_price = len_b - (b->index);
		if (b->target_node)
		{
			if (b->target_node->over_mid == 0)
				b->push_price += len_a - (b->target_node->index);
			else
				b->push_price += b->target_node->index;
		}
		b = b->next;
	}
}

void	init_node(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_node(a, b);
	set_price(a, b);
	get_cheapest_to_push(b);
}
