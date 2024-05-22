/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooore.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 04:54:18 by asebrani          #+#    #+#             */
/*   Updated: 2024/05/22 16:13:35 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check_accur(char *look, char c)
{
	int	i;

	i = 0;
	if (look[i] == '\0')
		return (0);
	while (look[i])
	{
		if (look[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_str(char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (!check_accur("+-0123456789", *str))
			return (1);
		if ((*str == '+' || *str == '-')
			&& !check_accur("0123456789", *(str + 1)))
			return (1);
		if ((*str == '+' || *str == '-')
			&& check_accur("0123456789", *(str + 1))
			&& check_accur("0123456789", *(str - 1)))
			return (1);
		str++;
	}
	return (0);
}

static	int	str_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (0);
	i = 0;
	j = str_len(s1);
	str = malloc(j + 1);
	if (str == 0)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
