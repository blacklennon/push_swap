/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 23:00:33 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/26 11:26:19 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_node		*is_in_list(int nb, char operation, t_node *lst)
{
	while (lst)
	{
		if (operation == '<')
		{
			if (lst->data < nb)
				return (lst);
		}
		else if (operation == '>')
		{
			if (lst->data > nb)
				return (lst);
		}
		else if (operation == '=')
		{
			if (lst->data == nb)
				return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}

int			which_side_of_list(int nb, t_node *node, t_node *lst)
{
	int		len;
	int		i;

	len = get_list_len(lst);
	i = 0;
	while (lst)
	{
		if (lst == node)
			break ;
		if (lst->data == nb && !node)
			break ;
		i++;
		lst = lst->next;
	}
	return (i > (len / 2) ? 2 : 1);
}

t_node		*get_max_before_last(t_node *lst)
{
	t_node	*tmp;
	t_node	*max;

	tmp = lst;
	max = get_max(lst);
	while (lst)
	{
		if (lst->data > tmp->data && lst != max)
			tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

static t_node	*get_min_max(t_node *lst, char c)
{
	t_node		*tmp;

	tmp = lst;
	if (c != '<' && c != '>')
		return (NULL);
	while (lst)
	{
		if (c == '<')
		{
			if (lst->data < tmp->data)
				tmp = lst;
		}
		else if (c == '>')
			if (lst->data > tmp->data)
				tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_node			*get_min(t_node *lst)
{
	return (get_min_max(lst, '<'));
}

t_node			*get_max(t_node *lst)
{
	return (get_min_max(lst, '>'));
}
