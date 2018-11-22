/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 04:36:56 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/21 04:36:59 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include "common.h"
#include "checker.h"

static void	interactive_print(t_node *a, t_node *b)
{
	system("clear");
	print_lists(a, b);
	usleep(200000);
}

static t_op	op_code_conversion(char *op)
{
	if (!ft_strcmp(op, "pa"))
		return (PA);
	else if (!ft_strcmp(op, "pb"))
		return (PB);
	else if (!ft_strcmp(op, "sa"))
		return (SA);
	else if (!ft_strcmp(op, "sb"))
		return (SB);
	else if (!ft_strcmp(op, "ss"))
		return (SS);
	else if (!ft_strcmp(op, "ra"))
		return (RA);
	else if (!ft_strcmp(op, "rb"))
		return (RB);
	else if (!ft_strcmp(op, "rr"))
		return (RR);
	else if (!ft_strcmp(op, "rra"))
		return (RRA);
	else if (!ft_strcmp(op, "rrb"))
		return (RRB);
	else if (!ft_strcmp(op, "rrr"))
		return (RRR);
	else
		return (ERROR);
}

int			read_op(t_node **a, t_node **b, int options)
{
	char	*tmp;
	int		op_counter;
	t_op	op_code;

	op_counter = 0;
	options = options & FLAG_INTERACTIVE ? 1 : 0;
	if (options)
		interactive_print(*a, *b);
	while (get_next_line(0, &tmp))
	{
		op_code = op_code_conversion(tmp);
		free(tmp);
		if (op_code == ERROR)
			exit_error("bad operation");
		do_op(a, b, op_code);
		if (options)
			interactive_print(*a, *b);
		op_counter++;
	}
	return (op_counter);
}
