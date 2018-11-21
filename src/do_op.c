/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:00:01 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/21 07:01:22 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	op_push_swap(t_node **a, t_node **b, t_op op)
{
	if (op == PA)
		push(b, a);
	else if (op == PB)
		push(a, b);
	else if (op == SA)
		swap(a);
	else if (op == SB)
		swap(b);
	else if (op == SS)
	{
		swap(a);
		swap(b);
	}
}

static void	op_rotate(t_node **a, t_node **b, t_op op)
{
	if (op == RA)
		rotate(a);
	else if (op == RB)
		rotate(b);
	else if (op == RR)
	{
		rotate(a);
		rotate(b);
	}
	else if (op == RRA)
		rev_rotate(a);
	else if (op == RRB)
		rev_rotate(b);
	else if (op == RRR)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
}

void		do_op(t_node **a, t_node **b, t_op op_code)
{
	if (op_code >= ERROR)
		return ;
	else if (op_code >= PA && op_code <= SS)
		op_push_swap(a, b, op_code);
	else
		op_rotate(a, b, op_code);
}
