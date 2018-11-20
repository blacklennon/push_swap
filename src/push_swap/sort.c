/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:21:04 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/15 11:21:15 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_stack_a(t_env *e)
{
	int		pivot;
	int		p;
	int		r;
	int		i;
	int		len;

	r = 0;
	i = 0;
	p = 0;
	if ((len = get_list_len(*(e->a))) < 3)
	{
		sort_three_or_less_ints(e);
		return (0);
	}
	pivot = get_median(*(e->a));
	while (is_in_list(pivot, '<', *(e->a)) && i++ < len)
	{
		if (e->a[0]->data < pivot && ++p)
			add_op(e, PB);
		else
		{
			add_op(e, RA);
			r++;
		}
	}
	sort_stack_a(e);
	while (p--)
		add_op(e, PA);
	return (0);
}

void	sort(t_env *e)
{
	sort_stack_a(e);
	add_op(e, END);
}
