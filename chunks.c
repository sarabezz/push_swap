/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:54:40 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/05 20:17:05 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

int	int_sqrt(int x)
{
	int	i;

	i = 0;
	while (i * i <= x)
		i++;
	return (i - 1);
}

int	*create_chunks(int *array, int total_size, int *chunks_num)
{
	int				*chunks;
	int				chunk_size;
	int				*sorted;	
	t_chunk_create	create_info;		

	if (!array || total_size <= 0)
		return (NULL);
	sorted = copy_sort(array, total_size);
	if (!sorted)
		return (NULL);
	chunk_size = (total_size + *chunks_num - 1) / *chunks_num;
	if (chunk_size == 0)
		chunk_size = 1;
	chunks = malloc(sizeof(int) * (*chunks_num));
	if (!chunks)
		return (free(sorted), NULL);
	create_info.chunks = chunks;
	create_info.sorted = sorted;
	create_info.chunk_size = chunk_size;
	create_info.total_size = total_size;
	create_info.chunks_num = *chunks_num;
	find_chunks_max(&create_info);
	free(sorted);
	return (chunks);
}

int	init_chunks_resources(t_chunk_info *info)
{
	int	i;

	info->sorted = copy_sort(info->array, info->total_size);
	if (!info->sorted)
		return (0);
	info->chunks = chunks_mem(info->total_size, info->chunks_num,
			info->chunk_sizes);
	if (!info->chunks)
	{
		free(info->sorted);
		return (0);
	}
	info->used = used_mem(info->total_size);
	if (!info->used)
	{
		free(info->sorted);
		i = 0;
		while (i < info->chunks_num)
			free(info->chunks[i++]);
		free(info->chunks);
		return (0);
	}
	return (1);
}
