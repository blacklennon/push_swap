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
void				add_op(t_env *e, t_op op_code);
void				sort_three_or_less_ints(t_env *e, t_list_name name, \
					int (*comparator)(int, int), int len);
void				sort(t_env *e);
void				quick_sort_a(t_env *e, int len);
int					get_median(t_node *lst, int len);
void				optimize_list(t_op *list);

#endif
