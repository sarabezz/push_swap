/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:21:36 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/21 20:53:27 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_array	*convert_to_array(t_stack *stack)
{
	int				size;
	int				*arr;
	t_stack_array	*sa;

	size = stack_size(stack);
	arr = stack_to_array(stack, size);
	sa = malloc(sizeof(t_stack_array));
	if (!sa)
		ft_error();
	sa->array = arr;
	sa->size = size;
	sa->capacity = size;
	return (sa);
}

void	insert_nums(t_stack **a, int *nums, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		push_no_count(a, nums[i]);
		i--;
	}
}

int	stack_size(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	if (!stack)
		return (0);
	count = 1;
	tmp = stack->next;
	while (tmp != stack)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	*stack_to_array(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	t_stack	*tmp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		ft_error();
	tmp = stack;
	i = 0;
	while (i < size)
	{
		arr[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*start;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	start = *stack;
	tmp = start->next;
	while (tmp != start)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(start);
	*stack = NULL;
}
