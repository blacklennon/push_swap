/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:09:21 by pcarles           #+#    #+#             */
/*   Updated: 2018/07/09 01:53:08 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
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

static void	sort(t_node **a, t_node **b)
{
	int		median;
	int		*tab;
	int		i;

	(void)b;
	i = 0;
	tab = transform_list_in_tab(*a);
	sort_tab(tab + 1, *tab);
	median = tab[(*tab / 2) + 1];
	while (i <= *tab)
	{
		system("clear");
		print_lists(*a, *b);
		sleep(1);
		while ((*a)->data > median)
			push(a, b, "pb");
		rotate(a, "ra");
		i++;
	}
	printf("mediane: %d\n", median);
	free(tab);
}

int			main(int ac, char **av)
{
	t_node	*lst_a;
	t_node	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (parse_ints(ac, av, &lst_a) == -1)
		exit_error();
	sort(&lst_a, &lst_b);
	print_lists(lst_a, lst_b);
	free_lst(lst_a);
	free_lst(lst_b);
	return (0);
}
