/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:33:24 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/21 19:03:30 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!stack || !node)
		return ;
	if (!*stack)
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

void	rra(t_stack **a)
{
	if (!(*a) || (*a)->prev == *a)
		return ;
	*a = (*a)->prev;
	printf("rra\n");
}

void	rrb(t_stack **b)
{
	if (!(*b) || (*b)->prev == *b)
		return ;
	*b = (*b)->prev;
	printf("rrb\n");
}

void	move_to_b(t_move_args *args)
{
	int	chunk;
	int	moved;
	int	top;
	int	chunk_size;

	chunk = 0;
	while (chunk < args->chunks_num)
	{
		moved = 0;
		chunk_size = stack_size(*(args->a));
		while (moved < chunk_size)
		{
			top = (*(args->a))->nbr;
			if (top <= args->chunks_max[chunks]
				&& !is_in_lis(top, args->lis, args->lis_size))
			{
				pb(args->a, args->b);
				moved++;
			}
			else
				ra(args->a);
		}
		chunk++;
	}
}

void	final_rotate(t_stack **a)
{
	int	min_index;
	int	size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (size <= 1)
		return ;
	min_index = get_min_index(*a);
	if (min_index <= size / 2)
		while (min_index-- > 0)
			ra(a);
	else
	{
		min_index = size - min_index;
		while (min_index-- > 0)
			rra(a);
	}
}
