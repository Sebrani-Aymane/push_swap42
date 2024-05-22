/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:54:25 by asebrani          #+#    #+#             */
/*   Updated: 2024/05/07 17:53:34 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (a == NULL)
		return ;
	curr = *a;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*a = NULL;
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == NULL)
		return ;
	while (*str)
	{
		free(str);
		i++;
	}
}

int	error_repetition(t_stack *a, int value)
{
	t_stack	*temp;

	if (NULL == a)
		return (1);
	while (a)
	{
		temp = a -> next;
		value = a->nbr;
		while (temp)
		{
			if (temp -> nbr == value)
				return (1);
			temp = temp -> next;
		}
		a = a->next;
	}
	return (0);
}

void	error_free(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit (1);
}
