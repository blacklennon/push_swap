/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */

/*   Created: 2018/06/23 17:32:40 by pcarles           #+#    #+#             */
/*   Updated: 2018/10/31 14:49:38 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "push_swap.h"

static long	ft_atoilong(char const *s)
{
	int		flag;
	long	res;

	flag = 0;
	res = 0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			flag = 1;
		s++;
	}
	while (*s <= '9' && *s >= '0')
	{
		res *= 10;
		res += *s - '0';
		s++;
	}
	if (flag)
		res = -res;
	return (res);
}

static int	arg_is_valid(char const *arg)
{
	char	*tmp;

	while (*arg)
	{
		while (*arg == ' ')
			arg++;
		if (*arg == '\0')
			return (1);
		if (*arg == '-')
			if (!ft_isdigit(*(++arg)))
				return (0);
		if (ft_isdigit(*arg))
		{
			tmp = (char *)arg;
			while (ft_isdigit(*arg))
				arg++;
			if (arg - tmp > 10 || (*arg != ' ' && *arg != '\0'))
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

static void	put_arg(char const *arg, t_node **lst)
{
	long		tmp;
	int			number;

	while (*arg)
	{
		tmp = ft_atoilong(arg);
		if (tmp > INT_MAX || tmp < INT_MIN)
			exit_error("int overflow");
		number = (int)tmp;
		if (is_in_list(number, '=', *lst))
			exit_error("there is a duplicate");
		*lst = new_node(*lst, number);
		while (*arg == ' ' && *arg)
			arg++;
		while ((ft_isdigit(*arg) || *arg == '-') && *arg)
			arg++;
	}
}

static int	parse_flags(int const ac, char const **av, int *options)
{
	int		i;

	*options = 0;
	i = 1;
	while (i < ac && *av[i] == '-')
	{
		if (!ft_strcmp(av[i], "-p"))
			*options |= FLAG_PRINT;
		else if (!ft_strcmp(av[i], "--csv"))
			*options |= FLAG_CSV;
		else if (!ft_strcmp(av[i], "-i"))
			*options |= FLAG_INTERACTIVE;
		else if (arg_is_valid(av[i]))
			break ;
		else
			return (-1);
		i++;
	}
	return (i);
}

int			parse(int const ac, char const **av, t_node **lst)
{
	int		options;
	int		i;

	options = 0;
	if (ac <= 1)
		return (-1);
	i = parse_flags(ac, av, &options);
	if (i == -1)
		return (-1);
	while (i < ac)
	{
		if (!arg_is_valid(av[i]))
			return (-2);
		put_arg(av[i], lst);
		i++;
	}
	return (options);
}
