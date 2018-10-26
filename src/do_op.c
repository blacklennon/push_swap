/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:00:01 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/26 15:06:59 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"
#include "push_swap.h"

static void	interactive_print(t_node *a, t_node *b)
{
	system("clear");
	print_lists(a, b);
}

int			do_op(t_node **a, t_node **b, int options)
{
	char	*tmp;
	int		op_counter;

	op_counter = 0;
	if (!(options & FLAG_INTERACTIVE))
		options = 0;
	else
		interactive_print(*a, *b);
	while (get_next_line(0, &tmp))
	{
		if (!ft_strcmp(tmp, "sa"))
			swap(a, NULL);
		else if (!ft_strcmp(tmp, "sb"))
			swap(b, NULL);
		else if (!ft_strcmp(tmp, "ss"))
		{
			swap(a, NULL);
			swap(b, NULL);
		}
		else if (!ft_strcmp(tmp, "pa"))
			push(b, a, NULL);
		else if (!ft_strcmp(tmp, "pb"))
			push(a, b, NULL);
		else if (!ft_strcmp(tmp, "ra"))
			rotate(a, NULL);
		else if (!ft_strcmp(tmp, "rb"))
			rotate(b, NULL);
		else if (!ft_strcmp(tmp, "rr"))
		{
			rotate(a, NULL);
			rotate(b, NULL);
		}
		else if (!ft_strcmp(tmp, "rra"))
			rev_rotate(a, NULL);
		else if (!ft_strcmp(tmp, "rrb"))
			rev_rotate(b, NULL);
		else if (!ft_strcmp(tmp, "rrr"))
		{
			rev_rotate(a, NULL);
			rev_rotate(b, NULL);
		}
		else
			return (-1);
		if (options)
			interactive_print(*a, *b);
		op_counter++;
	}
	return (op_counter);
}
