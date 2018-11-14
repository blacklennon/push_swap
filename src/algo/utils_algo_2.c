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

int		is_revert_sort(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->data < lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}
