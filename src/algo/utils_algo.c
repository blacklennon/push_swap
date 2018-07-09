/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 23:00:33 by pcarles           #+#    #+#             */
/*   Updated: 2018/07/09 23:06:35 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_in_list(int nb, char operation, t_node *lst)
{
	while (lst)
	{
		if (operation == '<')
		{
			if (lst->data < nb)
				return (1);
		}
		else if (operation == '>')
		{
			if (lst->data > nb)
				return (1);
		}
		else if (operation == '=')
		{
			if (lst->data == nb)
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}
