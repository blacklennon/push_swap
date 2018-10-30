/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:32:40 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/29 14:02:40 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static int	arg_is_valid(char const *arg)
{
	while (*arg)
	{
		if (!(ft_isdigit(*arg) || *arg == ' ' || *arg == '-'))
			return (0);
		arg++;
	}
	return (1);
}

static void	put_arg(char const *arg, t_node **lst)
{
	int		tmp;

	while (*arg)
	{
		tmp = ft_atoi(arg);
		if (is_in_list(tmp, '=', *lst))
			exit_error("there is a duplicate");
		*lst = new_node(*lst, tmp);
		while (*arg == ' ' && *arg)
			arg++;
		while ((ft_isdigit(*arg) || *arg == '-') && *arg)
			arg++;
	}
}

int			parse(int const ac, char const **av, t_node **lst)
{
	int		options;
	int		i;

	options = 0;
	i = 1;
	if (ac <= 1)
		return (-1);
	while (i < ac && *av[i] == '-')
	{
		if (!ft_strcmp(av[i], "-p"))
			options |= FLAG_PRINT;
		else if (!ft_strcmp(av[i], "--csv"))
			options |= FLAG_CSV;
		else if (!ft_strcmp(av[i], "-i"))
			options |= FLAG_INTERACTIVE;
		else if (arg_is_valid(av[i]))
			break ;
		else
			return (-1);
		i++;
	}
	while (i < ac)
	{
		if (!arg_is_valid(av[i]))
			return (-2);
		put_arg(av[i], lst);
		i++;
	}
	return (options);
}
