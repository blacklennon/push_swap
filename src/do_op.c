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
#include "push_swap.h"

static void	interactive_print(t_node *a, t_node *b)
{
	system("clear");
	print_lists(a, b);
	usleep(200000);
}

static int	op_push(t_node **a, t_node **b, char *op)
{
	if (!ft_strcmp(op, "pa"))
		push(b, a, NULL);
	else if (!ft_strcmp(op, "pb"))
		push(a, b, NULL);
	else
		return (-1);
	return (0);
}

static int	op_swap(t_node **a, t_node **b, char *op)
{
	if (!ft_strcmp(op, "sa"))
		swap(a, NULL);
	else if (!ft_strcmp(op, "sb"))
		swap(b, NULL);
	else if (!ft_strcmp(op, "ss"))
	{
		swap(a, NULL);
		swap(b, NULL);
	}
	else
		return (-1);
	return (0);
}

static int	op_rotate(t_node **a, t_node **b, char *op)
{
	if (!ft_strcmp(op, "ra"))
		rotate(a, NULL);
	else if (!ft_strcmp(op, "rb"))
		rotate(b, NULL);
	else if (!ft_strcmp(op, "rr"))
	{
		rotate(a, NULL);
		rotate(b, NULL);
	}
	else if (!ft_strcmp(op, "rra"))
		rev_rotate(a, NULL);
	else if (!ft_strcmp(op, "rrb"))
		rev_rotate(b, NULL);
	else if (!ft_strcmp(op, "rrr"))
	{
		rev_rotate(a, NULL);
		rev_rotate(b, NULL);
	}
	else
		return (-1);
	return (0);
}

int			do_op(t_node **a, t_node **b, int options)
{
	char	*tmp;
	int		op_counter;
	int		op_validity;

	op_counter = 0;
	options = options & FLAG_INTERACTIVE ? 1 : 0;
	if (options)
		interactive_print(*a, *b);
	while (get_next_line(0, &tmp))
	{
		if (*tmp == 's')
			op_validity = op_swap(a, b, tmp);
		else if (*tmp == 'p')
			op_validity = op_push(a, b, tmp);
		else if (*tmp == 'r')
			op_validity = op_rotate(a, b, tmp);
		else
			exit_error("bad operation");
		if (op_validity == -1)
			exit_error("bad operation");
		if (options)
			interactive_print(*a, *b);
		op_counter++;
	}
	return (op_counter);
}
