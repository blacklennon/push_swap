/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:32:40 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/15 20:53:57 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
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

// >>TODO<< change the falg system bc can't have
//          negative numbers at the begining of args.
int			parse_ints(int ac, char **av, t_node **lst)
{
	int		i;
	char	*tmp;

	i = 1;
	if (ac <= 1)
		return (-1);;
	if (*av[i] == '-')
		i++;
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

int			parse_flags(int ac, char **av)
{
	int		i;
	int		options;

	i = 1;
	options = 0;
	if (ac <= 1)
		return (-1);
	while (i < ac && *av[i] == '-')
	{
		if (!ft_strcmp(av[i], "-p"))
			options |= FLAG_PRINT;
		else if (!ft_strcmp(av[i], "--csv"))
			options |= FLAG_CSV;
		else
			return (-1);
		i++;
	}
	return (options);
}
