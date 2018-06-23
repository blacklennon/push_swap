/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:32:40 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/23 17:49:18 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		parse_ints(int ac, char **av, t_node **lst)
{
	int i;

	i = 1;
	if (ac <= 1)
		return (-1);
	while (i < ac)
	{
		*lst = new_node(*lst, ft_atoi(av[i]));
		i++;
	}
	return (0);
}
