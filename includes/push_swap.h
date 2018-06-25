/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:19:12 by pcarles           #+#    #+#             */
/*   Updated: 2018/06/26 01:17:04 by pcarles          ###   ########.fr       */
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

int					main(int ac, char **av);
void				swap(t_node *lst);
void				push(t_node **from, t_node **to);
void				rotate(t_node **lst);
void				rev_rotate(t_node **lst);
void				print_lists(t_node *a, t_node *b);
void				free_lst(t_node *lst);
int					parse_ints(int ac, char **av, t_node **lst);
t_node				*new_node(t_node *lst, int nb);
int					check(t_node **lst_a, t_node **lst_b);
int					is_sort(t_node *lst);
void				exit_error(void);

#endif
