/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 01:47:03 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/15 11:21:41 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

int			*transform_list_in_tab(t_node *lst)
{
	int		len;
	int		*res;

	len = get_list_len(lst);
	res = (int *)ft_memalloc(sizeof(*res) * (len + 1));
	if (!res)
		exit_error("malloc in transform_list_in_tab() failed");
	*res = len;
	len = 1;
	while (lst)
	{
		res[len] = lst->data;
		len++;
		lst = lst->next;
	}
	return (res);
}

int			*sort_tab(int *tab, int len)
{
	int		i;
	int		j;
	int		x;

	i = 1;
	while (i < len)
	{
		x = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > x)
		{
			tab[j] = tab[j - 1];
			j -= 1;
		}
		tab[j] = x;
		i++;
	}
	return (tab);
}

static void	push_median(int median, t_env e)
{
	t_node	*tmp;

	while ((tmp = is_in_list(median, '<', *(e.a))))
	{
		if ((*(e.a))->data < median)
			while ((*(e.a))->data < median)
				add_op(e, PB);
		else
		{
			if (which_side_of_list(0, tmp, *(e.a)) == 2)
				add_op(e, RRA);
			else
				add_op(e, RA);
		}
	}
}

void		median_presort(t_env e)
{
	int		median;
	int		*tab;

	while (!(get_list_len(*(e.a)) <= 3 || is_sort(*(e.a))))
	{
		tab = transform_list_in_tab(*(e.a));
		sort_tab(tab + 1, *tab);
		if (*tab <= 7)
			median = tab[((*tab + 1) / 2) + 1];
		else if (*tab <= 100)
			median = tab[((*tab + 1) / 3) + 1];
		else
			median = tab[((*tab + 1) / 6) + 1];
		push_median(median, e);
		free(tab);
	}
	if (!is_sort(*(e.a)))
		sort_three_or_less_ints(e);
}

void		insert_sort(t_env e)
{
	t_node	*max;
	t_node	*max_before_last;

	while (get_list_len(*(e.b)) > 0)
	{
		max = get_max(*(e.b));
		max_before_last = get_max_before_last(*(e.b));
		while (*(e.b) != max)
		{
			if (max_before_last == *(e.b) && max == (*(e.b))->next && \
				get_list_len(*(e.b)) > 2)
				add_op(e, SB);
			else
			{
				if (which_side_of_list(max->data, NULL, *(e.b)) == 2)
					add_op(e, RRB);
				else
					add_op(e, RB);
			}
		}
		add_op(e, PA);
	}
}
