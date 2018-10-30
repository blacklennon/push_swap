/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:49:11 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/29 14:00:32 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include "push_swap.h"

static void	sort_three_ints(t_node **lst, int a, int b, int c)
{
	if ((a > b && b > c) || \
		(a > b && a < c) || \
		(b > c && a < c))
		swap(lst, "sa");
	if (is_sort(*lst))
		return ;
	rotate(lst, NULL);
	if (is_sort(*lst))
		ft_putendl("ra");
	else
	{
		rev_rotate(lst, NULL);
		rev_rotate(lst, "rra");
	}
}

void		sort_three_or_less_ints(t_node **lst, char lst_name)
{
	int		a;
	int		b;
	int		c;

	if (is_sort(*lst))
		return ;
	if (get_list_len(*lst) == 2)
		swap(lst, lst_name == 'a' ? "sa" : "sb");
	else
	{
		a = (*lst)->data;
		b = (*lst)->next->data;
		c = (*lst)->next->next->data;
		sort_three_ints(lst, a, b, c);
	}
}
