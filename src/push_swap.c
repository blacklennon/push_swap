/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:09:21 by pcarles           #+#    #+#             */
/*   Updated: 2018/07/14 05:53:24 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

int			main(int ac, char **av)
{
	t_node	*lst_a;
	t_node	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (parse_ints(ac, av, &lst_a) == -1)
		exit_error();
	median_sort(&lst_a, &lst_b);
	print_lists(lst_a, lst_b);
	free_lst(lst_a);
	free_lst(lst_b);
	return (0);
}
