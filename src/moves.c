/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 00:36:43 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/01 01:06:28 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*swap(t_node *lst)
{
	int		tmp;

	if (lst)
	{
		if (lst->next)
		{
			tmp = lst->next->data;
			lst->next->data = lst->data;
			lst->data = tmp;
		}
	}
	return (lst);
}

t_node		*push(t_node **from, t_node **to)
{
	if (*from && *to)
	{
		if (*(from)->next)
			*(from)->next->prev = NULL;
		*(to)->prev = *from;
		*(from)->next = *to
	}
	return (to);
}
