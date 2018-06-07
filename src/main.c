/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:16:17 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/01 01:03:40 by pcarles          ###   ########.fr       */
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
	new->prev = NULL;
	new->next = NULL;
	if (!lst)
		return (new);
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	new->prev = lst;
	return (tmp);
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
	lst_a = swap(lst_a);

	while (lst_a)
	{
		printf("%d\n", lst_a->data);
		lst_a = lst_a->next;
	}
	printf("======= B =======");
	while (lst_b)
	{
		printf("%d\n", lst_b->data);
		lst_b = lst_b->next;
	}
	return (0);
}
