/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:21:04 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/15 11:21:15 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static t_node			*is_in_liste(int nb, char operation, t_node *lst,int len)
{
	while (len-- && lst)
	{
		if (operation == '<')
		{
			if (lst->data < nb)
				return (lst);
		}
		else if (operation == '>')
		{
			if (lst->data > nb)
				return (lst);
		}
		else if (operation == '=')
		{
			if (lst->data == nb)
				return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}

static void		backtrack(t_env *e, t_list_name name, int rotations)
{
	int len;
	t_node	**list;

	list = name == A ? e->a : e->b;
	len = get_list_len(*list);
	if (rotations > len / 2)
		while (len - rotations++ > 0)
			add_op(e, name == A ? RA : RB);
	else
		while (rotations--)
			add_op(e, name == A ? RRA : RRB);
}

void			sort_stack_b(t_env *e, int len)
{
	int		pivot;
	int		p;
	int		rotations;
	int		i;

	rotations = 0;
	i = 0;
	p = 0;
	if (len <= 3)
		return (sort_three_or_less_ints(e, B, &is_inferior, len));
	pivot = get_median(*(e->b), len);
	while (is_in_liste(pivot, '>', *(e->b), len - i) && i++ < len)
	{
		ft_putstr("it works\n");
		if (e->b[0]->data > pivot && ++p)
		{
			add_op(e, PA);
		}
		else
		{
			add_op(e, RB);
			rotations++;
		}
	}
	sort_stack_a(e, p);
	backtrack(e, B, rotations);
	sort_stack_b(e, len - p);
	while (p--)
		add_op(e, PB);
}

void			sort_stack_a(t_env *e, int len)
{
	int		pivot;
	int		p;
	int		rotations;
	int		i;

	rotations = 0;
	i = 0;
	p = 0;
	if (len <= 3)
		return (sort_three_or_less_ints(e, A, &is_superior, len));
	pivot = get_median(*(e->a), len);
	while (is_in_liste(pivot, '<', *(e->a), len - i) && i++ < len)
	{
		if (e->a[0]->data < pivot && ++p)
		{
			add_op(e, PB);
		}
		else
		{
			add_op(e, RA);
			rotations++;
		}
	}
	backtrack(e, A, rotations);
	sort_stack_a(e, len - p);
	sort_stack_b(e, p);
	while (p--)
		add_op(e, PA);
}

void	sort(t_env *e)
{
	sort_stack_a(e, get_list_len(*(e->a)));
}
