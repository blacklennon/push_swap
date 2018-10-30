/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:10:22 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/30 18:23:45 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

void		print_lists(t_node *a, t_node *b)
{
	printf("  a  |  b  \n-----+-----\n");
	while (a || b)
	{
		printf("%4d | %-4d\n", a ? a->data : 0, b ? b->data : 0);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}

void		print_return(t_node *a, t_node *b, int options, int op_counter)
{
	int		list_len;

	list_len = get_list_len(a) + get_list_len(b);
	if (is_sort(a) && !b)
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
		print_lists(a, b);
}
