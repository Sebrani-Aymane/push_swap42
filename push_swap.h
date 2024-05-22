/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:39:41 by asebrani          #+#    #+#             */
/*   Updated: 2024/05/22 16:27:35 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_price;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				cheapest_target;
	int				over_mid;
}	t_stack;

void	free_stack(t_stack **a);
void	free_str(char **str);
int		error_repetition(t_stack *a, int value);
void	pb(t_stack **b, t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		sorted_or_no(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
char	**split(char *str, char sep);
void	finish_rotation(t_stack **stack, t_stack *head_node, char stack_name);
void	push_swap(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	current_index(t_stack *stack);
void	get_cheapest_to_push(t_stack *b);
void	set_price(t_stack *a, t_stack *b);
void	init_node(t_stack *a, t_stack *b);
void	stack_init(t_stack **a, char **av);
t_stack	*get_last_node(t_stack *stack);
void	create_node(t_stack **stack, int value);
t_stack	*find_smallest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
int		stack_len(t_stack *stack);
void	error_free(t_stack **a);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
char	*join_it(char **strs);
int		check_str(char *str);
char	*ft_strdup(const char *s1);

#endif
