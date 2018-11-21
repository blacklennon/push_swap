/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:49:11 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/21 04:39:16 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static void	sort_three_ints(t_env *e, t_list_name name, \
			int (*comparator)(int, int))
{
	int		a;
	int		b;
	int		c;
	t_node	**list;

	list = name == A ? e->a : e->b;
	a = (*list)->data;
	b = (*list)->next->data;
	c = (*list)->next->next->data;
	if ((comparator(a, b) && comparator(b, c)) || \
		(comparator(a, b) && !comparator(a, c)) || \
		(comparator(b, c) && !comparator(a, c)))
		add_op(e, name == A ? SA : SB);
	if (is_sort_n(*list, comparator, 3))
		return ;
	add_op(e, name == A ? RA : RB);
	if (is_sort_n(*list, comparator, 3))
		return ;
	else
	{
		add_op(e, name == A ? RRA : RRB);
		add_op(e, name == A ? RRA : RRB);
	}
}

static void	sort_three_ints_safe(t_env *e, t_list_name name, \
			int (*comparator)(int, int), int len)
{
	t_node	**list;

	list = name == A ? e->a : e->b;
	while (len-- > 1)
	{
		if (comparator((*list)->data, (*list)->next->data))
		{
			add_op(e, name == A ? SA : SB);
			add_op(e, name == A ? RA : RB);
		}
		else
			add_op(e, name == A ? RA : RB);
	}
	while (++len < 3)
		add_op(e, name == A ? RRA : RRB);
	if (comparator((*list)->data, (*list)->next->data))
		add_op(e, name == A ? SA : SB);
}

void		sort_three_or_less_ints(t_env *e, t_list_name name, \
			int (*comparator)(int, int), int len)
{
	t_node	**list;

	list = name == A ? e->a : e->b;
	if (len == 1)
		return ;
	if (is_sort_n(*list, comparator, len))
		return ;
	if (len == 2 && comparator((*list)->data, (*list)->next->data))
		add_op(e, name == A ? SA : SB);
	else if (len == 3 && get_list_len(*list) == 3)
		sort_three_ints(e, name, comparator);
	else
		sort_three_ints_safe(e, name, comparator, len);
}
