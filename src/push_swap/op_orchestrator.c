/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_orchestrator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 04:40:52 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/21 04:43:53 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static void		print_op(t_op op)
{
	if (op == PA)
		ft_putstr("pa\n");
	else if (op == PB)
		ft_putstr("pb\n");
	else if (op == SA)
		ft_putstr("sa\n");
	else if (op == SB)
		ft_putstr("sb\n");
	else if (op == SS)
		ft_putstr("ss\n");
	else if (op == RA)
		ft_putstr("ra\n");
	else if (op == RB)
		ft_putstr("rb\n");
	else if (op == RR)
		ft_putstr("rr\n");
	else if (op == RRA)
		ft_putstr("rra\n");
	else if (op == RRB)
		ft_putstr("rrb\n");
	else if (op == RRR)
		ft_putstr("rrr\n");
}

static void		print_op_list(t_op *op_list, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		print_op(op_list[i]);
		i++;
	}
}

static void		append_to_list(t_env *e, t_op op_code)
{
	static int	index = 0;
	static int	nb_malloc = 1;
	t_op		*tmp;

	if (index < OP_LIST_BUFF_SIZE * nb_malloc)
		e->op_list[index++] = op_code;
	else
	{
		tmp = (t_op *)ft_memalloc(sizeof(t_op) * \
		(++nb_malloc * OP_LIST_BUFF_SIZE));
		if (!tmp)
			exit_error("realloc failed in add_op");
		ft_memcpy(tmp, e->op_list, sizeof(t_op) * \
			(OP_LIST_BUFF_SIZE * (nb_malloc - 1)));
		free(e->op_list);
		e->op_list = tmp;
		e->op_list[index++] = op_code;
	}
	if (op_code == END)
	{
		optimize_list(e->op_list);
		print_op_list(e->op_list, index);
	}
}

void			add_op(t_env *e, t_op op_code)
{
	if (op_code == ERROR)
		return ;
	do_op(e->a, e->b, op_code);
	if (!(e->op_list))
	{
		e->op_list = (t_op *)ft_memalloc(sizeof(t_op) * OP_LIST_BUFF_SIZE);
		if (!e->op_list)
			exit_error("malloc failed in add_op");
		append_to_list(e, op_code);
	}
	else
		append_to_list(e, op_code);
}
