/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 07:05:18 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/21 07:05:23 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "push_swap.h"

static void		backtrack(t_env *e, t_list_name name, int rotations)
{
	int			len;
	t_node		**list;

	list = name == A ? e->a : e->b;
	len = get_list_len(*list);
	if (rotations > len / 2)
		while (len - rotations++ > 0)
			add_op(e, name == A ? RA : RB);
	else
		while (rotations--)
			add_op(e, name == A ? RRA : RRB);
}

static void		quick_sort_b(t_env *e, int len)
{
	int			pivot;
	int			push;
	int			rotations;
	int			i;

	push = 0;
	rotations = 0;
	i = 0;
	if (len <= 3)
		return (sort_three_or_less_ints(e, B, &is_inferior, len));
	pivot = get_median(*(e->b), len);
	while (is_in_list(pivot, *(e->b), &is_superior, len - i) && i++ < len)
		if (e->b[0]->data > pivot && ++push)
			add_op(e, PA);
		else
		{
			add_op(e, RB);
			rotations++;
		}
	quick_sort_a(e, push);
	backtrack(e, B, rotations);
	quick_sort_b(e, len - push);
	while (push--)
		add_op(e, PB);
}

void			quick_sort_a(t_env *e, int len)
{
	int			pivot;
	int			push;
	int			rotations;
	int			i;

	push = 0;
	rotations = 0;
	i = 0;
	if (len <= 3)
		return (sort_three_or_less_ints(e, A, &is_superior, len));
	pivot = get_median(*(e->a), len);
	while (is_in_list(pivot, *(e->a), &is_inferior, len - i) && i++ < len)
		if (e->a[0]->data < pivot && ++push)
			add_op(e, PB);
		else
		{
			add_op(e, RA);
			rotations++;
		}
	backtrack(e, A, rotations);
	quick_sort_a(e, len - push);
	quick_sort_b(e, push);
	while (push--)
		add_op(e, PA);
}

void			sort(t_env *e)
{
	quick_sort_a(e, get_list_len(*(e->a)));
	add_op(e, END);
}
