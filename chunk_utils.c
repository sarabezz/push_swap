/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 01:51:20 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/05 20:18:02 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

int	*used_mem(int total_size)
{
	int	*used;
	int	i;

	i = 0;
	used = malloc(sizeof(int) * total_size);
	if (!used)
		return (NULL);
	while (i < total_size)
	{
		used[i] = 0;
		i++;
	}
	return (used);
}

int	**allocate_chunks(int chunks_num, int total_size)
{
	int	**chunks;
	int	c;

	c = 0;
	chunks = malloc(sizeof(int *) * chunks_num);
	if (!chunks)
		return (NULL);
	while (c < chunks_num)
	{
		chunks[c] = malloc(sizeof(int) * total_size);
		if (!chunks[c])
		{
			while (c >= 0)
				free(chunks[c--]);
			free(chunks);
			return (NULL);
		}
		c++;
	}
	return (chunks);
}

int	**chunks_mem(int total_size, int chunks_num, int *chunk_sizes)
{
	int	**chunks;
	int	i;

	i = 0;
	chunks = allocate_chunks(chunks_num, total_size);
	if (!chunks)
		return (NULL);
	if (chunk_sizes)
	{
		while (i < chunks_num)
		{
			chunk_sizes[i] = 0;
			i++;
		}
	}
	return (chunks);
}

void	process_chunks(t_chunk_info *info)
{
	int	i;
	int	c;
	int	index;

	c = 0;
	while (c < info->chunks_num)
	{
		i = 0;
		while (i < info->total_size)
		{
			if (!info->used[i] && info->sorted[i] <= info->chunks_max[c])
			{
				index = info->chunk_sizes[c]++;
				info->chunks[c][index] = info->sorted[i];
				info->used[i] = 1;
			}
			i++;
		}
		c++;
	}
}
