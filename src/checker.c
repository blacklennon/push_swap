/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 00:18:58 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/26 11:07:37 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int			check(t_node **lst_a, t_node **lst_b)
{
	char	*tmp;

	while (get_next_line(0, &tmp))
	{
		if (!ft_strcmp(tmp, "sa"))
			swap(*lst_a);	
		else if (!ft_strcmp(tmp, "sb"))
			swap(*lst_b);
		else if (!ft_strcmp(tmp, "ss"))
		{
			swap(*lst_a);
			swap(*lst_b);
		}	
		else if (!ft_strcmp(tmp, "pa"))
			push(lst_b, lst_a);
		else if (!ft_strcmp(tmp, "pb"))
			push(lst_a, lst_b);	
		else if (!ft_strcmp(tmp, "ra"))
			rotate(lst_a);
		else if (!ft_strcmp(tmp, "rb"))
			rotate(lst_b);
		else if (!ft_strcmp(tmp, "rr"))
		{
			rotate(lst_a);
			rotate(lst_b);
		}
		else if (!ft_strcmp(tmp, "rra"))
			rev_rotate(lst_a);
		else if (!ft_strcmp(tmp, "rrb"))
			rev_rotate(lst_b);
		else if (!ft_strcmp(tmp, "rrr"))
		{
			rev_rotate(lst_a);
			rev_rotate(lst_b);
		}
		else if (!ft_strcmp(tmp, ""))
			return (0);
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
