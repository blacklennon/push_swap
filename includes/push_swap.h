/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:19:12 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/14 17:09:05 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define DEBUG 1
# define FLAG_PRINT 0x1
# define FLAG_CSV 0x2
# define FLAG_INTERACTIVE 0x4

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

/*
** ================ Functions prototypes
*/

int					main(int const ac, char const **av);

/*
** ================ Moves
*/

void				swap(t_node **lst, char *to_write);
void				push(t_node **from, t_node **to, char *to_write);
void				rotate(t_node **lst, char *to_write);
void				rev_rotate(t_node **lst, char *to_write);

/*
** ================ Parser
*/

int					parse(int const ac, char const **av, t_node **lst);
int					do_op(t_node **a, t_node **b, int options);

/*
** ================ Utils
*/

void				print_lists(t_node *a, t_node *b);
void				print_return(t_node *a, t_node *b, \
					int options, int op_counter);
void				free_lst(t_node *lst);
t_node				*new_node(t_node *lst, int nb);
void				exit_error(char *str);

/*
** ================ Utils algo
*/

int					is_sort(t_node *lst);
int					get_list_len(t_node *lst);
int					which_side_of_list(int nb, t_node *node, t_node *lst);
t_node				*is_in_list(int nb, char operation, t_node *lst);
t_node				*get_min(t_node *lst);
t_node				*get_max(t_node *lst);
t_node				*get_max_before_last(t_node *lst);

int					*transform_list_in_tab(t_node *lst);
int					*sort_tab(int *tab, int len);
int					is_revert_sort(t_node *lst);

/*
** ================ Algo
*/

void				sort_three_or_less_ints(t_node **lst, char lst_name);
void				median_presort(t_node **a, t_node **b);
void				insert_sort(t_node **a, t_node **b);
void				sort(t_node **a, t_node **b);
void				master_blast_sort(t_node **a, t_node **b);

#endif
