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

static void	sort_three_ints(t_env *e, int x, int y, int z)
{
	if ((x > y && y > z) || \
		(x > y && x < z) || \
		(y > z && x < z))
		add_op(e, SA);
	if (is_sort(*(e->a)))
		return ;
	add_op(e, RA);
	if (is_sort(*(e->a)))
		return ;
	else
	{
		add_op(e, RRA);
		add_op(e, RRA);
	}
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

void		sort_three_or_less_ints(t_env *e)
{
	int		x;
	int		y;
	int		z;

	if (is_sort(*(e->a)))
		return ;
	if (get_list_len(*(e->a)) == 2)
		add_op(e, SA);
	else
	{
		x = (*(e->a))->data;
		y = (*(e->a))->next->data;
		z = (*(e->a))->next->next->data;
		sort_three_ints(e, x, y, z);
	}
}

int			get_median(t_node *lst)
{
	int		len;
	int		*res;

	len = get_list_len(lst);
	res = (int *)ft_memalloc(sizeof(*res) * len);
	if (!res)
		exit_error("malloc in transform_list_in_tab() failed");
	len = 0;
	while (lst)
	{
		res[len] = lst->data;
		len++;
		lst = lst->next;
	}
	res = sort_tab(res, len);
	return (res[len/2]);
}