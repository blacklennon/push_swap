/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:09:21 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/15 08:38:48 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int				main(int const ac, char const **av)
{
	t_node		*lst_a;
	t_node		*lst_b;
	t_op		*op_list;
	t_env		e;

	lst_a = NULL;
	lst_b = NULL;
	op_list = NULL;
	if (parse(ac, av, 1, &lst_a))
		exit_error("parse error");
	e.a = &lst_a;
	e.b = &lst_b;
	e.op_list = op_list;
	sort(&e);
	return (0);
}
