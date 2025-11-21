/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:31:11 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/21 19:08:25 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push_no_count(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*last;

	node = create_node(value);
	if (!node)
		return ;
	if (!(*stack))
	{
		node->next = node;
		node->prev = node;
		*stack = node;
	}
	else
	{
		last = (*stack)->prev;
		node->next = *stack;
		node->prev = last;
		last->next = node;
		(*stack)->prev = node;
		*stack = node;
	}
}

int	is_in_lis(int value, int *lis, int lis_size)
{
	int	i;

	i = 0;
	while (i < lis_size)
	{
		if (lis[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	remove_node(t_stack **stack)
{
	t_stack	*last;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	if ((*stack)->next == *stack)
	{
		*stack = NULL;
		return ;
	}
	last = (*stack)->prev;
	next = (*stack)->next;
	last->next = next;
	next->prev = last;
	*stack = next;
}
