/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 23:00:33 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/21 06:49:02 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

int		is_superior(int a, int b)
{
	return (a > b);
}

int		is_inferior(int a, int b)
{
	return (a < b);
}

int		is_equal(int a, int b)
{
	return (a == b);
}

t_node	*is_in_list(int nb, t_node *lst, int (*comparator)(int, int), int len)
{
	while (lst && len--)
	{
		if (comparator(lst->data, nb))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int		is_sort_n(t_node *lst, int (*comparator)(int, int), int len)
{
	if (!lst)
		return (0);
	if (len <= 0)
		return (0);
	len--;
	while (lst->next && len)
	{
		if (comparator(lst->data, lst->next->data))
			return (0);
		lst = lst->next;
		len--;
	}
	return (1);
}
