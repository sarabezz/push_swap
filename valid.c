/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:30:51 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/19 21:24:49 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_isnumber(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		ft_error();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error();
		i++;
	}
	return (1);
}

int	ft_atoi_checked(const char *str)
{
	long	n;

	if (!ft_isnumber(str))
		ft_error();
	n = (long)ft_atoi(str);
	if (n > INT_MAX || n < INT_MIN)
		ft_error();
	return ((int)n);
}

int	dupl_nums(int argc, int *nums)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (nums[i] == nums[j])
				ft_error();
			j++;
		}
		i++;
	}
	return (0);
}
