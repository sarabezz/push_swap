/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:46:41 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/05 18:05:09 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static int	cmp_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	*copy_sort(int *array, int size)
{
	int	*sorted;
	int	i;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = array[i];
		i++;
	}
	qsort(sorted, size, sizeof(int), cmp_int);
	return (sorted);
}

void	find_chunks_max(t_chunk_create *create_info)
{
	int	i;
	int	index;

	i = 0;
	while (i < create_info->chunks_num)
	{
		index = create_info->chunk_size * (i + 1) - 1;
		if (index >= create_info->total_size)
			index = create_info->total_size - 1;
		create_info->chunks[i] = create_info->sorted[index];
		i++;
	}
}
