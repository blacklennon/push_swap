/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:09:21 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/29 05:37:46 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_list **a, t_list **b)
{
	if ((*a)->data > (*a)->next->data)
		push(a, b, "pb");
}

int			main(int ac, char **av)
{
	t_node	*lst_a;
	t_node	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (parse_ints(ac, av, &lst_a) == -1)
		exit_error();
	print_lists(lst_a, lst_b);
	free_lst(lst_a);
	free_lst(lst_b);
	return (0);
}
