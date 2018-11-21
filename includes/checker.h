/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 07:39:36 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/21 07:39:38 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define FLAG_PRINT 0x1
# define FLAG_CSV 0x2
# define FLAG_INTERACTIVE 0x4

int					main(int const ac, char const **av);

int					read_op(t_node **a, t_node **b, int options);

void				print_lists(t_node *a, t_node *b);
void				print_return(t_node *a, t_node *b, \
					int options, int op_counter);

#endif
