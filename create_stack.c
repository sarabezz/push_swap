/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:21:36 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/19 21:34:09 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_args(int argc, char **argv)
{
	int		*nums;
	int		i;

	if (argc < 2)
		ft_error();
	nums = malloc(sizeof(int) * (argc - 1));
	if (!nums)
		ft_error();
	i = 1;
	while (i < argc)
	{
		nums[i - 1] = ft_atoi_checked(argv[i]);
		i++;
	}
	return (nums);
}

/*int	*parse_args(int argc, char **argv, int *out_size)
{
	int		*nums;
	int		i;

	if (argc < 2)
		ft_error();
	nums = malloc(sizeof(int) * (argc - 1));
	if (!nums)
		ft_error();
	i = 1;
	while (i < argc)
	{
		nums[i - 1] = ft_atoi_checked(argv[i]);
		i++;
	}
	if (dupl_nums(argc - 1, nums))
	{
		free(nums);
		ft_error();
	}
	*out_size = argc - 1;
	return (nums);
}*/

void	fill_stack(t_stack **a, int *nums, int size)
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
