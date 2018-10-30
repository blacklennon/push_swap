/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 00:18:58 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/30 18:44:06 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
#include "push_swap.h"

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
		exit_error("usage: ./checker [options] numbers...\
\n  options:\n    -p, Print the two lists\n");
	else if (options == -2)
		exit_error("parse error");
	list_len = get_list_len(lst_a);
	if (!lst_a)
		exit_error("empty list");
	op_counter = do_op(&lst_a, &lst_b, options);
	if (op_counter == -1)
		exit_error("invalid command");
	print_return(lst_a, lst_b, options, op_counter);
	free_lst(lst_a);
	free_lst(lst_b);
	return (0);
}
