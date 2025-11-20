/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:52:17 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/05 03:02:07 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	init_arrays(int *dp, int *prev, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dp[i] = 1 ;
		prev[i] = -1 ;
		i++;
	}
}

static void	fill_dp(int *array, int *dp, int *prev, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] < array[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

static int	get_max_index(int *dp, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (dp[i] > dp[max])
			max = i;
		i++;
	}
	return (max);
}

static int	*reconstruct(int *array, int *prev, int *lis_size, int max)
{
	int	*lis;
	int	i;

	lis = malloc(sizeof(int) * (*lis_size));
	if (!lis)
		return (NULL);
	i = *lis_size - 1;
	while (i >= 0)
	{
		lis[i] = array[max];
		max = prev[max];
		i--;
	}
	return (lis);
}

int	*longest_increasing_subsequence(int *array, int size, int *lis_size)
{
	int	*dp;
	int	*prev;
	int	*lis;
	int	max;

	dp = malloc(sizeof(int) * size);
	if (!dp)
		return (NULL);
	prev = malloc(sizeof(int) * size);
	if (!prev)
	{
		free(dp);
		return (NULL);
	}
	init_arrays(dp, prev, size);
	fill_dp(array, dp, prev, size);
	max = get_max_index(dp, size);
	*lis_size = dp[max];
	lis = reconstruct(array, prev, lis_size, max);
	free(dp);
	free(prev);
	return (lis);
}

/*
int main(void)
{
    int array[] = {27, -8, 14, -34, 42, 1, -12, 5, -25, 36,
                   19, -7, 0, -3, 48, -18, 33, 8, -11, 4,
                   21, -2, 13, -27, 9, -5, 6, 40, -1, 30};
    int size = sizeof(array) / sizeof(array[0]);
    int lis_size;
    int *lis = longest_increasing_subsequence(array, size, &lis_size);

    printf("LIS size: %d\n", lis_size);
    printf("LIS: ");
    for (int i = 0; i < lis_size; i++)
        printf("%d ", lis[i]);
    printf("\n");

    free(lis);
    return (0);
}
*/