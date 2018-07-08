/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 00:18:58 by pcarles           #+#    #+#             */
/*   Updated: 2018/07/08 04:53:04 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	check(t_node **lst_a, t_node **lst_b)
{
	char	*tmp;

	while (get_next_line(0, &tmp))
	{
		if (!ft_strcmp(tmp, "sa"))
			swap(*lst_a, NULL);
		else if (!ft_strcmp(tmp, "sb"))
			swap(*lst_b, NULL);
		else if (!ft_strcmp(tmp, "ss"))
		{
			swap(*lst_a, NULL);
			swap(*lst_b, NULL);
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
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_node	*lst_a;
	t_node	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (parse_ints(ac, av, &lst_a) == -1)
		exit_error();
	if (check(&lst_a, &lst_b) == -1)
		exit_error();
	if (is_sort(lst_a) && !lst_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	print_lists(lst_a, lst_b);
	free_lst(lst_a);
	free_lst(lst_b);
	return (0);
}
