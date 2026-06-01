/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 02:04:49 by sarabermude       #+#    #+#             */
/*   Updated: 2025/10/05 20:56:13 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack	t_stack;

t_stack	*create_node(int value);

typedef struct s_stack_array
{
	int	*array;
	int	size;
	int	capacity;
}	t_stack_array;

typedef struct s_chunk_create_info
{
	int	total_size;
	int	*sorted;
	int	*chunks;
	int	chunk_size;
	int	chunks_num;
}	t_chunk_create;

typedef struct s_chunk_info
{
	int	*array;
	int	total_size;
	int	chunks_num;
	int	*chunk_sizes;
	int	*chunks_max;
	int	*sorted;
	int	*used;
	int	**chunks;
}	t_chunk_info;

// --- Funciones de chunks ---
int		*copy_sort(int *array, int size);
void	find_chunks_max(t_chunk_create *create_info);
int		*used_mem(int total_size);
int		**allocate_chunks(int chunks_num, int total_size);
int		**chunks_mem(int total_size, int chunks_num, int *chunk_sizes);
void	process_chunks(t_chunk_info *info);
int		int_sqrt(int x);
int		*create_chunks(int *array, int total_size, int *chunks_num);
int		init_chunks_resources(t_chunk_info *info);

// --- LIS (Longest Increasing Subsequence) ---
int		*longest_increasing_subsequence(int *array, int size, int *lis_size);

// --- Cálculo coste mínimo
int		get_cost_a(t_stack_array *a, int value);
int		adjust_cost(int cost, int size);
int		find_min_cost(t_stack_array *a, t_stack_array *b,
			int *best_a, int *best_b);
int		total_cost(int ca, int cb);

#endif
