/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:14:13 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/21 20:59:10 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_sort_info(t_stack **a, t_chunk_info *info,
		int *chunks_num)
{
	int		*arr;

	arr = stack_to_array(*a, stack_size(*a));
	*chunks_num = int_sqrt(stack_size(*a));
	info->array = arr;
	info->total_size = stack_size(*a);
	info->chunks_num = *chunks_num;
	info->chunks_max = NULL;
	info->chunk_sizes = NULL;
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	t_chunk_info	info;
	t_move_args		move_args;
	t_sort_vars		vars;

	initialize_sort_info(a, &info, &vars.chunks_num);
	vars.lis = longest_increasing_subsequence(info.array,
			info.total_size, &vars.lis_size);
	vars.chunks = get_chunks(&info);
	free(info.array);
	move_args.a = a;
	move_args.b = b;
	move_args.chunks_max = info.chunks_max;
	move_args.chunks_num = vars.chunks_num;
	move_elements_to_b(&move_args, vars.lis, vars.lis_size);
	free(vars.lis);
	free(vars.chunks);
	move_elements_to_a(a, b);
}

static int	*split_to_ints(char **parts, int size)
{
	int	*nums;
	int	i;

	nums = malloc(sizeof(int) * size);
	if (!nums)
		ft_error();
	i = 0;
	while (i < size)
	{
		nums[i] = ft_atoi_checked(parts[i]);
		i++;
	}
	return (nums);
}

void	parse_args(t_stack **a, char *arg)
{
	char	**parts;
	int		*nums;
	int		size;

	parts = ft_split(arg, ' ');
	if (!parts)
		ft_error();
	size = 0;
	while (parts[size])
		size++;
	nums = split_to_ints(parts, size);
	insert_nums(a, nums, size);
	free(nums);
	ft_free_split(parts);
}

void	fill_stack(t_stack **a, int argc, char **argv)
{
	int		i;
	char	**parts;
	int		size;
	int		*nums;

	i = argc - 1;
	while (i >= 1)
	{
		parts = ft_split(argv[i], ' ');
		if (!parts)
			ft_error();
		size = 0;
		while (parts[size])
			size++;
		nums = split_to_ints(parts, size);
		insert_nums(a, nums, size);
		free(nums);
		ft_free_split(parts);
		i--;
	}
}
