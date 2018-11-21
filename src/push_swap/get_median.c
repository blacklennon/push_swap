/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 04:39:47 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/21 04:40:23 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "common.h"
#include "push_swap.h"

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
