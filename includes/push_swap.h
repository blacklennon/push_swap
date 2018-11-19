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

#include "common.h"

typedef struct		s_env
{
	struct s_node	**a;
	struct s_node	**b;
	enum e_op		*op_list;
}					t_env;

int					main(int const ac, char const **av);
int					which_side_of_list(int nb, t_node *node, t_node *lst);
t_node				*get_min(t_node *lst);
t_node				*get_max(t_node *lst);
t_node				*get_max_before_last(t_node *lst);
int					is_revert_sort(t_node *lst);
void        		add_op(t_env *e, t_op op_code);
void				sort_three_or_less_ints(t_env *e);
void				median_presort(t_env e);
void				insert_sort(t_env e);
void				sort(t_env *e);
int					get_median(t_node *lst);

#endif
