/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:41:36 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/21 20:48:07 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	fill_stack(&a, argc, argv);
	arr = stack_to_array(a, stack_size(a));
	if (dupl_nums(stack_size(a), arr))
		ft_error();
	free(arr);
	sort_stacks(&a, &b);
	free_stack(&a);
	return (0);
}
