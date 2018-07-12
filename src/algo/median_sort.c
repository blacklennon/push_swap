/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 01:47:03 by pcarles           #+#    #+#             */
/*   Updated: 2018/07/12 08:00:02 by pcarles          ###   ########.fr       */
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
	res = (int *)ft_memalloc(sizeof(*res) * i + 1);
	if (!res)
		exit_error();
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
	t_node	*tmp;
	while (get_list_len(*b) > 0)
	{
		tmp = get_min(*b);
		if (tmp == *b)
		{
			push(b, a, "pa");
			rotate(a, "ra");
		}
		else
		{
			while (*b != tmp)
				rev_rotate(b, "rra");
			push(b, a, "pa");
			rotate(a, "ra");
		}
	}
}

static void	sort_three_ints(t_node **lst)
{
	t_node	*tmp;

	tmp = get_min(*lst);
	if (tmp == *lst)
	{
		if (get_min((*lst)->next) != (*lst)->next)
		{
			rotate(lst, "ra");
			swap(*lst, "sa");
			rev_rotate(lst, "rra");
		}
	}
}
void		median_sort(t_node **a, t_node **b)
{
	int		median;
	int		*tab;
	int		i;

	i = 0;
	if (get_list_len(*a) <= 3 || is_sort(*a))
	{
		sort_three_ints(a);
		return ;
	}
	tab = transform_list_in_tab(*a);
	sort_tab(tab + 1, *tab);
	median = tab[(*tab / 2) + 1];
	while (is_in_list(median, '>', *a))
	{
		if ((*a)->data > median)
			while ((*a)->data > median)
				push(a, b, "pb");
		else
			rotate(a, "ra");
		i++;
	}
	median_sort(a, b);
	median_sort_pt2(a, b);
//	printf("mediane: %d\n", median);
	free(tab);
}
