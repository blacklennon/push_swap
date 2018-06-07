/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:16:17 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/07 20:17:34 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*new_node(t_node *lst, int nb)
{
	t_node	*new;
	t_node	*tmp;

	tmp = lst;
	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->data = nb;
	new->next = NULL;
	if (!lst)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (lst);
}

int			main(int ac, char **av)
{
	t_node	*lst_a;
	t_node	*lst_b;
	int		i;

	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	if (ac <= 1)
		return (0);
	while (i < ac)
	{
		lst_a = new_node(lst_a, ft_atoi(av[i]));
		i++;
	}
	rev_rotate(&lst_a);
	print_lists(lst_a, lst_b);
	free_lst(lst_a);
	free_lst(lst_b);
	return (0);
}
