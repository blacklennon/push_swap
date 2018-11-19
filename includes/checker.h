#ifndef CHECKER_H
# define CHECKER_H

# define FLAG_PRINT 0x1
# define FLAG_CSV 0x2
# define FLAG_INTERACTIVE 0x4

#include "common.h"

int					main(int const ac, char const **av);
int					read_op(t_node **a, t_node **b, int options);
void				print_lists(t_node *a, t_node *b);
void				print_return(t_node *a, t_node *b, \
					int options, int op_counter);

#endif