/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:10:22 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/01 16:49:58 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "common.h"
#include "checker.h"

void		print_lists(t_node *a, t_node *b)
{
	ft_putstr("  a  |  b  \n-----+-----\n");
	while (a || b)
	{
		if (a)
			if (b)
				ft_printf("%4d | %-4d\n", a->data, b->data);
			else
				ft_printf("%4d |\n", a->data);
		else
			if (b)
				ft_printf("     | %-4d\n", b->data);
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
			ft_printf("OK;%d;%d\n", list_len, op_counter);
		else
			ft_putstr("OK\n");
	}
	else
	{
		if (options & FLAG_CSV)
			ft_printf("KO;%d;%d\n", list_len, op_counter);
		else
			ft_putstr("KO\n");
	}
	if ((options & FLAG_PRINT) && !(options & FLAG_INTERACTIVE))
		print_lists(a, b);
}
