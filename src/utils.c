/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:38:52 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/30 18:36:03 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "common.h"

t_node		*new_node(t_node *lst, int nb)
{
	t_node	*new;
	t_node	*tmp;

	tmp = lst;
	new = (t_node *)ft_memalloc(sizeof(*new));
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

void		free_lst(t_node *lst)
{
	if (lst)
	{
		free_lst(lst->next);
		free(lst);
	}
}

void		exit_error(char *str)
{
	if (str && DEBUG)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(str, 2);
	}
	else
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

int			is_sort(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->data < lst->next->data)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}

int			get_list_len(t_node *lst)
{
	int		res;

	res = 0;
	while (lst)
	{
		res++;
		lst = lst->next;
	}
	return (res);
}
