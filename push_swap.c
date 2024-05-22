/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:54:40 by asebrani          #+#    #+#             */
/*   Updated: 2024/05/19 21:42:23 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_all(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_all(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	finish_rotation(t_stack **stack, t_stack *head_node, char stack_name)
{
	while (*stack != head_node)
	{
		if (stack_name == 'a')
		{
			if (head_node->over_mid == 1)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (head_node->over_mid == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	from_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node != NULL
		&& cheapest_node->target_node != NULL
		&& cheapest_node->over_mid == 1
		&& cheapest_node->target_node->over_mid == 1)
		rotate_all(a, b, cheapest_node);
	else if (cheapest_node != NULL
		&& cheapest_node->target_node != NULL
		&& cheapest_node->over_mid == 0
		&& cheapest_node->target_node->over_mid == 0)
		reverse_rotate_all(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a);
	}
	sort_three(a);
	while (*b)
	{
		init_node(*a, *b);
		from_b_to_a(a, b);
	}
	current_index(*a);
	smallest = find_smallest(*a);
	if (smallest->over_mid == 1)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
