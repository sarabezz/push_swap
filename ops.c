/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:40 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/19 21:34:31 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*a) || (*a)->next == *a)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	*a = second;
	printf("sa\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!*b)
		return ;
	node = *b;
	if ((*b)->next == *b)
		*b = NULL;
	else
		remove_node(b);
	push_node(a, node);
	printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!*a)
		return ;
	node = *a;
	if ((*a)->next == *a)
		*a = NULL;
	else
		remove_node(a);
	push_node(b, node);
	printf("pb\n");
}

void	ra(t_stack **a)
{
	if (!(*a) || (*a)->next == *a)
		return ;
	*a = (*a)->next;
	printf("ra\n");
}

void	rb(t_stack **b)
{
	if (!(*b) || (*b)->next == *b)
		return ;
	*b = (*b)->next;
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
