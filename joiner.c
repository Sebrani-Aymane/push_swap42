/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joiner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:21:50 by asebrani          #+#    #+#             */
/*   Updated: 2024/05/22 16:33:08 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	size_t	count_len(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

static	void	copy_it(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
}

static	char	*str_joiner(char *s1, char *s2)
{
	char	*ret;

	if (!s1)
		return (ft_strdup(s2));
	ret = malloc(sizeof(char) * (count_len(s1) + count_len(s2) + 1));
	if (!ret)
		return (NULL);
	copy_it(ret, s1);
	copy_it(ret + count_len(s1), s2);
	free(s1);
	return (ret);
}

int	yes_or_no(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= '9' && str[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

char	*join_it(char **strs)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = NULL;
	if (!strs || !*strs)
		return (NULL);
	while (strs[i])
	{
		if (strs[i][0] == 0 || yes_or_no(strs[i]) == 1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		ret = str_joiner(ret, " ");
		ret = str_joiner(ret, strs[i++]);
	}
	return (ret);
}
