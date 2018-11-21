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
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int			is_superior(int a, int b)
{
	return (a > b);
}

int			is_inferior(int a, int b)
{
	return (a < b);
}

static void	sort_three_ints(t_env *e, t_list_name name, int (*comparator)(int, int))
{
	int a;
	int b;
	int c;
	t_node **list;

	list = name == A ? e->a : e->b;
	a = (*list)->data;
	b = (*list)->next->data;
	c = (*list)->next->next->data;
	if ((comparator(a, b) && comparator(b, c)) || \
		(comparator(a, b) && !comparator(a, c)) || \
		(comparator(b, c) && !comparator(a, c)))
		add_op(e, name == A ? SA : SB);
	if (is_sort_n(*list, comparator, 3))
		return ;
	add_op(e, name == A ? RA : RB);
	if (is_sort_n(*list, comparator, 3))
		return ;
	else
	{
		add_op(e, name == A ? RRA : RRB);
		add_op(e, name == A ? RRA : RRB);
	}
}

static void	sort_three_begin(t_env *e, t_list_name name, int (*comparator)(int, int), int len)
{
	t_node **list;

	list = name == A ? e->a : e->b;
	while (len-- > 1)
	{
		if (comparator((*list)->data, (*list)->next->data))
		{
			add_op(e, name == A ? SA : SB);
			add_op(e, name == A ? RA : RB);
		}
		else
			add_op(e, name == A ? RA : RB);
	}
	while (++len < 3)
		add_op(e, name == A ? RRA : RRB);
	if (comparator((*list)->data, (*list)->next->data))
		add_op(e, name == A ? SA : SB);
}

void		sort_three_or_less_ints(t_env *e, t_list_name name, int (*comparator)(int, int), int len)
{
	t_node	**list;

	list = name == A ? e->a : e->b;
	if (len == 1)
		return ;
	if (is_sort_n(*list, comparator, len))
		return ;
	if (len == 2 && comparator((*list)->data, (*list)->next->data))
		add_op(e, name == A ? SA : SB);
	else if (len == 3 && get_list_len(*list) == 3)
		sort_three_ints(e, name, comparator);
	else
		sort_three_begin(e, name, comparator, len);
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

int			get_median(t_node *lst, int len)
{
	int		i;
	int		*tab;
	int		n;

	i = 0;
	n = len;
	tab = (int *)ft_memalloc(sizeof(*tab) * len);
	if (!tab)
		exit_error("malloc in transform_list_in_tab() failed");
	while (lst && n)
	{
		tab[i++] = lst->data;
		lst = lst->next;
		n--;
	}
	tab = sort_tab(tab, len);
	i = tab[len / 2];
	free(tab);
	return (i);
}