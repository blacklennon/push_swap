/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:38:52 by pcarles           #+#    #+#             */
/*   Updated: 2018/07/08 04:47:47 by pcarles          ###   ########.fr       */
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

void		exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
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
