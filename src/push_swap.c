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

int			main(int const ac, char const **av)
{
	t_node	*lst_a;
	t_node	*lst_b;
	int		parse_result;

	lst_a = NULL;
	lst_b = NULL;
	parse_result = parse(ac, av, &lst_a);
	if (parse_result == -1 || parse_result == -2)
		exit_error("parse error");
	sort(&lst_a, &lst_b);
	free_lst(lst_a);
	free_lst(lst_b);
	return (0);
}
