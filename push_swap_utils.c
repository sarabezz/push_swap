/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 21:08:08 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/19 14:26:18 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack *a)
{
	int		size;
	int		min_index;
	int		min_value;
	int		i;
	t_stack	*tmp;

	size = stack_size(a);
	min_index = 0;
	min_value = a->nbr;
	tmp = a;
	i = 0;
	while (i < size)
	{
		if (tmp->nbr < min_value)
		{
			min_value = tmp->nbr;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}

static void	rotate_to_index(t_stack **stack, int index, int size, char stack_id)
{
	if (index <= size / 2)
	{
		while (index-- > 0)
		{
			if (stack_id == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		index = size - index;
		while (index-- > 0)
		{
			if (stack_id == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	move_elements_to_b(t_move_args *move_args, int *lis, int lis_size)
{
	move_args->lis = lis;
	move_args->lis_size = lis_size;
	move_to_b(move_args);
}

void	move_elements_to_a(t_stack **a, t_stack **b)
{
	t_stack_array	*arr_a;
	t_stack_array	*arr_b;
	int				best_a;
	int				best_b;

	while (stack_size(*b) > 0)
	{
		arr_a = convert_to_array(*a);
		arr_b = convert_to_array(*b);
		find_min_cost(arr_a, arr_b, &best_a, &best_b);
		rotate_to_index(b, best_b, arr_b->size, 'b');
		rotate_to_index(a, best_a, arr_a->size, 'a');
		pa(a, b);
		free(arr_a->array);
		free(arr_a);
		free(arr_b->array);
		free(arr_b);
	}
	final_rotate(a);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
