/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:00:01 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/01 16:48:06 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include "common.h"

static void	op_push(t_node **a, t_node **b, t_op op)
{
	if (op == PA)
		push(b, a);
	else if (op == PB)
		push(a, b);
}

static void	op_swap(t_node **a, t_node **b, t_op op)
{
	if (op == SA)
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

void	do_op(t_node **a, t_node **b, t_op op_code)
{
	if (op_code == PA || op_code == PB)
		op_push(a, b, op_code);
	else if (op_code == SA || op_code == SB || op_code == SS)
		op_swap(a, b, op_code);
	else
		op_rotate(a, b, op_code);
}