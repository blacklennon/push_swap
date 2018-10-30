/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 01:47:03 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/29 14:10:43 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static int	*transform_list_in_tab(t_node *lst)
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

static int	*sort_tab(int *tab, int len)
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

static void	push_median(int median, t_node **a, t_node **b)
{
	t_node	*tmp;

	while ((tmp = is_in_list(median, '<', *a)))
	{
		if ((*a)->data < median)
			while ((*a)->data < median)
				push(a, b, "pb");
		else
		{
			if (which_side_of_list(0, tmp, *a) == 2)
				rev_rotate(a, "rra");
			else
				rotate(a, "ra");
		}
	}
}

void		median_presort(t_node **a, t_node **b)
{
	int		median;
	int		*tab;

	while (!(get_list_len(*a) <= 3 || is_sort(*a)))
	{
		tab = transform_list_in_tab(*a);
		sort_tab(tab + 1, *tab);
		if (*tab <= 7)
			median = tab[((*tab + 1) / 2) + 1];
		else if (*tab <= 100)
			median = tab[((*tab + 1) / 3) + 1];
		else
			median = tab[((*tab + 1) / 6) + 1];
		push_median(median, a, b);
		free(tab);
	}
	if (!is_sort(*a))
		sort_three_or_less_ints(a, 'a');
	return ;
}

void		insert_sort(t_node **a, t_node **b)
{
	t_node	*max;
	t_node	*max_before_last;

	while (get_list_len(*b) > 0)
	{
		max = get_max(*b);
		max_before_last = get_max_before_last(*b);
		while (*b != max)
		{
			if (max_before_last == *b && max == (*b)->next && \
				get_list_len(*b) > 2)
				swap(b, "sb");
			else
			{
				if (which_side_of_list(max->data, NULL, *b) == 2)
					rev_rotate(b, "rrb");
				else
					rotate(b, "rb");
			}
		}
		push(b, a, "pa");
	}
}
