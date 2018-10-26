/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 01:47:03 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/23 18:47:53 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

static int	*transform_list_in_tab(t_node *lst)
{
	int		i;
	int		*res;

	i = get_list_len(lst);
	res = (int *)ft_memalloc(sizeof(*res) * (i + 1));
	if (!res)
		exit_error("malloc in transform_list_in_tab() failed");
	*res = i;
	i = 1;
	while (lst)
	{
		res[i] = lst->data;
		i++;
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
			j = j - 1;
		}
		tab[j] = x;
		i++;
	}
	return (tab);
}

static void	median_sort_pt2(t_node **a, t_node **b)
{
	t_node	*max;
	t_node	*max_before_last;

	while (get_list_len(*b) > 0)
	{
		max = get_max(*b);
		max_before_last = get_min_before_last(*b);
		while (*b != max)
		{	
			if (max_before_last == *b && max == (*b)->next && get_list_len(*b) > 2)
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

static void	sort_three_ints(t_node **lst)
{
	t_node	*tmp;

	if (is_sort(*lst))
		return ;
	tmp = get_min(*lst);
	if (tmp == *lst)
	{
		if (get_min((*lst)->next) != (*lst)->next)
		{
			rotate(lst, "ra");
			swap(lst, "sa");
			rev_rotate(lst, "rra");
		}
	}
	else
	{
		while (tmp != *lst)
			rotate(lst, "ra");
	}
	sort_three_ints(lst);
}

static void	median_sort_pt1(t_node **a, t_node **b)
{
	t_node	*tmp;
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
		free(tab);
	}
	if (!is_sort(*a))
		sort_three_ints(a);
	return ;
}

void		median_sort(t_node **a, t_node **b)
{
	median_sort_pt1(a, b);
	median_sort_pt2(a, b);
}
