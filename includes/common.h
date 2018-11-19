#ifndef COMMON_H
# define COMMON_H

# define DEBUG 1

typedef enum		e_op
{
					PA,
					PB,
					SA,
					SB,
					SS,
					RA,
					RB,
					RR,
					RRA,
					RRB,
					RRR,
					ERROR,
					END
}					t_op;

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

void				swap(t_node **lst);
void				push(t_node **from, t_node **to);
void				rotate(t_node **lst);
void				rev_rotate(t_node **lst);
void				do_op(t_node **a, t_node **b, t_op op_code);
int					parse(int const ac, char const **av, int index, t_node **lst);
void				free_lst(t_node *lst);
t_node				*new_node(t_node *lst, int nb);
void				exit_error(char *str);
int					is_sort(t_node *lst);
int					get_list_len(t_node *lst);
t_node				*is_in_list(int nb, char operation, t_node *lst);

#endif
