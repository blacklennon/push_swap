/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:38:52 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/26 00:16:01 by pcarles          ###   ########.fr       */
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

void		print_lists(t_node *a, t_node *b)
{
	printf(" a | b \n=======\n");
	while (a || b)
	{
		printf("%2d | %-2d\n", a ? a->data : 0, b ? b->data : 0);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}

void		free_lst(t_node *lst)
{
	if (lst)
	{
		free_lst(lst->next);
		free(lst);
	}
}
