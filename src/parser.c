/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:32:40 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/26 00:13:15 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_is_valid(char *arg)
{
	while (*arg)
	{
		if (!(ft_isdigit(*arg) || *arg == ' ' || *arg == '-'))
			return (0);
		arg++;
	}
	return (1);
}

static void	put_arg(char *arg, t_node **lst)
{
	while (*arg)
	{
		*lst = new_node(*lst, ft_atoi(arg));
		while (*arg == ' ' && *arg)
			arg++;
		while ((ft_isdigit(*arg) || *arg == '-') && *arg)
			arg++;
	}
}

int			parse_ints(int ac, char **av, t_node **lst)
{
	int		i;
	char	*tmp;

	i = 1;
	if (ac <= 1)
		return (0);
	while (i < ac)
	{
		tmp = ft_strdup(av[i]);
		if (!arg_is_valid(tmp))
			return (-1);
		put_arg(tmp, lst);
		ft_strdel(&tmp);
		i++;
	}
	return (0);
}
