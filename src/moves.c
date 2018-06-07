/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 00:36:43 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/07 20:04:49 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_node *lst)
{
	int		tmp;

	if (lst && lst->next)
	{
		tmp = lst->next->data;
		lst->next->data = lst->data;
		lst->data = tmp;
	}
}

void		push(t_node **from, t_node **to)
{
	t_node	*tmp;

	if (*from)
	{
		tmp = *to;
		*to = *from;
		*from = (*from)->next;
		(*to)->next = tmp;
	}
}

void		rotate(t_node **lst)
{
	t_node	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *lst;
		*lst = (*lst)->next;
		tmp->next->next = NULL;
	}
}

void		rev_rotate(t_node **lst)
{
	t_node	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		while (tmp->next)
		{
			if (!tmp->next->next)
			{
				tmp->next->next = *lst;
				*lst = tmp->next;
				tmp->next = NULL;
			}
			else
				tmp = tmp->next;
		}
	}
}
