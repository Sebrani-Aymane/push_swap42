/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:15:26 by asebrani          #+#    #+#             */
/*   Updated: 2024/05/22 17:15:15 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	new->next = tmp;
	*lst = new;
}

int	space_time(const char **str)
{
	int	sign;

	sign = 1;
	while (**str && ((**str >= 9 && **str <= 13) || **str == 32))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static long	ft_atol(const char *str)
{
	long	num;
	int		i;
	int		sign;

	num = 0;
	i = 0;
	sign = space_time(&str);
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if ((num > 2147483647 && sign == 1)
			|| ((num > 2147483648) && sign == -1))
			return (2147483648);
		str++;
	}
	return (num * sign);
}

static void	clear_strss(char **strs, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(strs[i++]);
	free(strs);
}

void	stack_init(t_stack **a, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (check_str(av[i]) == 1)
			error_free(a);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a);
		create_node(a, (int)nbr);
		++i;
	}
	clear_strss(av, i);
	if (error_repetition(*a, (int)nbr))
		error_free(a);
}
