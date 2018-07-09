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

int		which_side_of_list(int nb, t_node *lst)
{
	int	len;
	int	i;

	len = get_list_len(lst);
	i = 0;
	while (lst)
	{
		if (lst->data == nb)
			break ;
		i++;
		lst = lst->next;
	}
	return (i > (len / 2) ? 2 : 1);
}
