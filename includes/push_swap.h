/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:19:12 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/14 17:09:05 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define OP_LIST_BUFF_SIZE 100

# include "common.h"

typedef struct		s_env
{
	struct s_node	**a;
	struct s_node	**b;
	enum e_op		*op_list;
}					t_env;

typedef enum		e_list_name
{
	A,
	B
}					t_list_name;

int					main(int const ac, char const **av);
int					which_side_of_list(int nb, t_node *node, t_node *lst);
t_node				*get_min(t_node *lst);
t_node				*get_max(t_node *lst);
t_node				*get_max_before_last(t_node *lst);
int					is_revert_sort(t_node *lst);
int					is_sort_n(t_node *lst, int (*comparator)(int, int), int len);
void        		add_op(t_env *e, t_op op_code);
void				sort_three_or_less_ints(t_env *e, t_list_name name, int (*comparator)(int, int), int len);
void				median_presort(t_env e);
void				insert_sort(t_env e);
void				sort(t_env *e);
int					get_median(t_node *lst, int len);
void				sort_stack_a(t_env *e, int len);
void				sort_stack_b(t_env *e, int len);
int					is_superior(int a, int b);
int					is_inferior(int a, int b);

#endif
