/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:19:12 by pcarles           #+#    #+#             */
/*   Updated: 2018/07/08 04:47:50 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct		s_lists
{
	t_node			*a;
	t_node			*b;
}					t_lists;

int					main(int ac, char **av);
void				swap(t_node *lst, char *to_write);
void				push(t_node **from, t_node **to, char *to_write);
void				rotate(t_node **lst, char *to_write);
void				rev_rotate(t_node **lst, char *to_write);
void				print_lists(t_node *a, t_node *b);
void				free_lst(t_node *lst);
int					parse_ints(int ac, char **av, t_node **lst);
t_node				*new_node(t_node *lst, int nb);
int					is_sort(t_node *lst);
void				exit_error(void);
int					get_list_len(t_node *lst);

#endif
