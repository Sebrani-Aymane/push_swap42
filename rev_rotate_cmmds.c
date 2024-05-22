/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_cmmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:54:47 by asebrani          #+#    #+#             */
/*   Updated: 2024/05/07 17:28:19 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_lstprev(t_stack **head)
{
	t_stack	*cur;
	t_stack	*prev;

	cur = *head;
	prev = NULL;
	if (head && *head)
	{
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return (prev);
}

static	void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (stack == NULL || *stack == NULL
		|| (*stack)->next == NULL)
		return ;
	last = get_last_node(*stack);
	prev = ft_lstprev(stack);
	ft_lstadd_front(stack, last);
	prev->next = NULL;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
