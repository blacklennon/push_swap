/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 04:44:29 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/21 04:45:32 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	optimize(t_op *list, t_op first, t_op second)
{
	t_op	*current;
	t_op	*next;
	int		ret;

	ret = 0;
	while (*list != END)
	{
		current = list++;
		while (*list == EMPTY)
			list++;
		if (*list == END)
			return (ret);
		next = list;
		if ((*current == first && *next == second) || \
			(*current == second && *next == first))
		{
			*current = EMPTY;
			*next = EMPTY;
			ret = 1;
		}
		list = next;
	}
	return (ret);
}

void		optimize_list(t_op *list)
{
	int		i;

	i = 1;
	while (i)
	{
		i = 0;
		i |= optimize(list, SA, SA);
		i |= optimize(list, SB, SB);
		i |= optimize(list, RA, RRA);
		i |= optimize(list, RB, RRB);
		i |= optimize(list, PA, PB);
	}
}
