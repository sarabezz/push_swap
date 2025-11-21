/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarabermudez <sarabermudez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:39:28 by sarabermude       #+#    #+#             */
/*   Updated: 2025/11/21 20:53:39 by sarabermude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "array.h"
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_move_args
{
	t_stack	**a;
	t_stack	**b;
	int		*lis;
	int		lis_size;
	int		*operations;
}	t_move_args;

typedef struct s_sort_vars
{
	int		*lis;
	int		lis_size;
	int		**chunks;
	int		chunks_num;
}	t_sort_vars;

// --- Funciones de validación ---
void			ft_error(void);
int				ft_atoi_checked(const char *str);
int				ft_isnumber(const char *str);
int				dupl_nums(int argc, int *nums);

// --- Funciones de operación ---
void			push_no_count(t_stack **stack, int value);
int				is_in_lis(int value, int *lis, int lis_size);
void			remove_node(t_stack **stack);
void			move_to_b(t_move_args *args);
void			final_rotate(t_stack **a);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			push_node(t_stack **stack, t_stack *node);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);

// --- Funciones push_swap --- 
t_stack_array	*convert_to_array(t_stack *stack);
void			insert_nums(t_stack **a, int *nums, int size);
int				stack_size(t_stack *stack);
int				*stack_to_array(t_stack *stack, int size);
void			free_stack(t_stack **stack);
int				get_min_index(t_stack *a);
void			move_elements_to_b(t_move_args *move_args,
					int *lis, int lis_size);
void			move_elements_to_a(t_stack **a, t_stack **b);
void			ft_free_split(char **split);
void			sort_stacks(t_stack **a, t_stack **b);
void			parse_args(t_stack **a, char *arg);
void			fill_stack(t_stack **a, int argc, char **argv);
int				main(int argc, char **argv);

#endif