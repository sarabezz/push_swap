/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:07:02 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/19 14:17:48 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost_a(t_stack_array *a, int value)
{
	int	i;
	int	prev_index;
	int	prev;
	int	curr;

	i = 0;
	if (a->size == 0)
		return (0);
	while (i < a->size)
	{
		prev_index = i - 1;
		if (prev_index < 0)
			prev_index = a->size - 1;
		prev = a->array[prev_index];
		curr = a->array[i];
		if ((prev < value && value < curr)
			|| (prev > curr && (value > prev || value < curr)))
			return (i);
		i++;
	}
	return (i);
}

int	adjust_cost(int cost, int size)
{
	if (cost > size / 2)
		return (cost - size);
	if (cost < -size / 2)
		return (cost + size);
	return (cost);
}

int	find_min_cost(t_stack_array *a, t_stack_array *b, int *best_a, int *best_b)
{
	int	index;
	int	best_cost;
	int	cost_a;
	int	cost_b;
	int	cost;

	best_cost = 2147483647;
	index = 0;
	while (index < b->size)
	{
		cost_a = adjust_cost(get_cost_a(a, b->array[index]), a->size);
		cost_b = index;
		if (cost_b > b->size / 2)
			cost_b -= b->size;
		cost = total_cost(cost_a, cost_b);
		if (cost < best_cost)
		{
			best_cost = cost;
			*best_a = get_cost_a(a, b->array[index]);
			*best_b = index;
		}
		index++;
	}
	return (best_cost);
}

int	total_cost(int ca, int cb)
{
	if (ca * cb > 0)
	{
		if (abs(ca) > abs(cb))
			return (abs(ca));
		else
			return (abs(cb));
	}
	return (abs(ca) + abs(cb));
}
