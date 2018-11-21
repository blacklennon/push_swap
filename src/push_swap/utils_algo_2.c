/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:06:44 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/14 17:16:40 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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