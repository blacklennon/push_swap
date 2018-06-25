/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:16:17 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/26 01:05:45 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_node	*lst_a;
	t_node	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (parse_ints(ac, av, &lst_a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (check(&lst_a, &lst_b) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (is_sort(lst_a) && !lst_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	print_lists(lst_a, lst_b);
	free_lst(lst_a);
	free_lst(lst_b);
	return (0);
}
