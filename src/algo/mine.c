/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mine.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:23:40 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/14 17:38:12 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int			get_median(t_node *lst)
{
	int		*tab;

	tab = transform_list_in_tab(lst);
	sort_tab(tab + 1, *tab);
	return (tab[(*tab / 2) + 1]);
}

void		master_blast_pt_2(t_node **a, t_node **b)
{
	t_node	*max_b;
	t_node	*min_b;

	max_b = get_max(*b);
	min_b = get_min(*b);
	while (!is_sort(*a) && !is_revert_sort(*b))
	{
		if (get_list_len(*b) >= 2 && (*a)->data > (*a)->next->data)
		{
			if ((*b)->data < (*b)->next->data && (*b != min_b && (*b)->next != max_b))
			{
				swap(a, NULL);
				swap(b, "ss");
			}
			swap(a, "sa");
		}
		else if (get_list_len(*b) >= 2 && (*b)->data < (*b)->next->data && (*b != min_b && (*b)->next != max_b))
			swap(b, "sb");
		rotate(a, NULL);
		rotate(b, "rr");	
	}
}

void		master_blast_sort(t_node **a, t_node **b)
{
	int		median;

	median = get_median(*a);
	while (is_in_list(median, '<', *a))
	{
		if (get_list_len(*b) >= 2 && (*a)->data < (*a)->next->data)
		{
			if ((*b)->data > (*b)->next->data)
			{
				swap(a, NULL);
				swap(b, "ss");
			}
			swap(a, "sa");
		}
		else if (get_list_len(*b) >= 2 && (*b)->data > (*b)->next->data)
			swap(b, "sb");
		if ((*a)->data <= median)
			push(a, b, "pb");
		else
			rotate(a, "ra");
	}
	master_blast_pt_2(a, b);
}
