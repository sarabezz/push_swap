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

void rotate_both(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    // mientras ambos positivos → rr
    while (cost_a > 0 && cost_b > 0)
    {
        rr(a, b);
        cost_a--;
        cost_b--;
    }
    // mientras ambos negativos → rrr
    while (cost_a < 0 && cost_b < 0)
    {
        rrr(a, b);
        cost_a++;
        cost_b++;
    }
    // el que queda lo hace solo
    while (cost_a > 0) { ra(a); cost_a--; }
    while (cost_a < 0) { rra(a); cost_a++; }
    while (cost_b > 0) { rb(b); cost_b--; }
    while (cost_b < 0) { rrb(b); cost_b++; }
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
	int             cost_a;
    int             cost_b;

	while (stack_size(*b) > 0)
	{
		arr_a = convert_to_array(*a);
		arr_b = convert_to_array(*b);
		find_min_cost(arr_a, arr_b, &best_a, &best_b);
		if (best_a <= arr_a->size / 2)
            cost_a = best_a;
        else
            cost_a = best_a - arr_a->size;
        if (best_b <= arr_b->size / 2)
            cost_b = best_b;
        else
            cost_b = best_b - arr_b->size;
        rotate_both(a, b, cost_a, cost_b);
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
