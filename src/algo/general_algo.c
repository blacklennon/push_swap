/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:49:11 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/26 19:20:13 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include "push_swap.h"

static void	sort_three_ints(t_node **lst, char lst_name, int a, int b, int c)
{
	if ((a > b && b > c) ||\
		(a > b && a < c) ||\
		(b > c && a < c))
		swap(lst, lst_name == 'a' ? "sa" : "sb");
	if (is_sort(*lst))
		return ;
	rotate(lst, NULL);
	if (is_sort(*lst))
		ft_putendl(lst_name == 'a' ? "ra" : "rb");
	else
	{
		rev_rotate(lst, NULL);
		rev_rotate(lst, lst_name == 'a' ? "rra" : "rrb");
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
		sort_three_ints(lst, lst_name, a, b, c);
	}
}
