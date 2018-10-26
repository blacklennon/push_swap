/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 00:18:58 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/23 18:35:18 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
#include "push_swap.h"

static int	check(t_node **lst_a, t_node **lst_b)
{
	char	*tmp;
	int		op_counter;

	op_counter = 0;
	while (get_next_line(0, &tmp))
	{
		if (!ft_strcmp(tmp, "sa"))
			swap(lst_a, NULL);
		else if (!ft_strcmp(tmp, "sb"))
			swap(lst_b, NULL);
		else if (!ft_strcmp(tmp, "ss"))
		{
			swap(lst_a, NULL);
			swap(lst_b, NULL);
		}
		else if (!ft_strcmp(tmp, "pa"))
			push(lst_b, lst_a, NULL);
		else if (!ft_strcmp(tmp, "pb"))
			push(lst_a, lst_b, NULL);
		else if (!ft_strcmp(tmp, "ra"))
			rotate(lst_a, NULL);
		else if (!ft_strcmp(tmp, "rb"))
			rotate(lst_b, NULL);
		else if (!ft_strcmp(tmp, "rr"))
		{
			rotate(lst_a, NULL);
			rotate(lst_b, NULL);
		}
		else if (!ft_strcmp(tmp, "rra"))
			rev_rotate(lst_a, NULL);
		else if (!ft_strcmp(tmp, "rrb"))
			rev_rotate(lst_b, NULL);
		else if (!ft_strcmp(tmp, "rrr"))
		{
			rev_rotate(lst_a, NULL);
			rev_rotate(lst_b, NULL);
		}
		else
			return (-1);
		op_counter++;
	}
	return (op_counter);
}

int			main(int const ac, char const **av)
{
	int		options;
	int		op_counter;
	int		list_len;
	t_node	*lst_a;
	t_node	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	options = parse(ac, av, &lst_a);
	if (options == -1)
		exit_usage();
	else if (options == -2)
		exit_error("parse error");
	list_len = get_list_len(lst_a);
	if (!lst_a)
		exit_error("empty list");
	op_counter = check(&lst_a, &lst_b);
	if (op_counter == -1)
		exit_error("invalid command (available commads: sx, ss, px, rx, rr, rrx, rrr, with x = a or x = b)");
	if (is_sort(lst_a) && !lst_b)
	{
		if (options & FLAG_CSV)
			printf("OK;%d;%d\n", list_len, op_counter);
		else
			ft_putstr("OK\n");
	}
	else
	{
		if (options & FLAG_CSV)
			printf("KO;%d;%d\n", list_len, op_counter);
		else
			ft_putstr("KO\n");
	}
	if (options & FLAG_PRINT)
		print_lists(lst_a, lst_b);
	free_lst(lst_a);
	free_lst(lst_b);
	return (0);
}
