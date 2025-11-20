/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:14:13 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/19 21:00:04 by sarabermude      ###   ########.fr       */
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

static void	sort_stacks(t_stack **a, t_stack **b)
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
	move_elements_to_b(&move_args, vars.lis, vars.lis_size);
	free(vars.lis);
	free(vars.chunks);
	move_elements_to_a(a, b);
}

void	parse_and_fill(t_stack **a, char *arg)
{
	char	**parts;
	int		i;

	i = 0;
	parts = ft_split(arg, ' ');
	if (!parts)
		ft_error();
	while (parts[i])
	{
		push_no_count(a, ft_atoi_checked(parts[i]));
		i++;
	}
	ft_free_split(parts);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;
	int			*arr;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		parse_and_fill(&a, argv[i]);
		i++;
	}
	arr = stack_to_array(a, stack_size(a));
	if (dupl_nums(stack_size(a), arr))
		ft_error();
	free(arr);
	sort_stacks(&a, &b);
	free_stack(&a);
	return (0);
}

/*int	main(int argc, char **argv)
{
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	int		*nums;
	int		size;
	int		i;

	nums = parse_args(argc, argv, &size);
	i = size - 1;
	while (i >= 0)
		push_no_count(&a, nums[i--]);
	free(nums);
	sort_stacks(&a, &b);
	free_stack(&a);
	return (0);
}*/