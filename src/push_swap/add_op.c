#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static void print(t_op *op_list, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        ft_printf("op_code: %d\n", op_list[i]);
        i++;
    }
}

static void add(t_op *op_list, t_op op_code)
{
    static int  index = 0;
    t_op        *tmp;

    if (op_code == END)
        print(op_list, index);
    if (index <= OP_LIST_BUFF_SIZE)
        op_list[index++] = op_code;
    else
    {
        tmp = ft_memalloc(sizeof(*tmp) * (index + OP_LIST_BUFF_SIZE));
        ft_memcpy(op_list, tmp, index);
        free(op_list);
        op_list = tmp;
        op_list[index++] = op_code;
    }
}

void        add_op(t_env *e, t_op op_code)
{
    if (!op_code || op_code == ERROR)
        return;
    do_op(e->a, e->b, op_code);
    if (!(e->op_list))
    {
        ft_putstr("malloc\n");
        e->op_list = (t_op *)ft_memalloc(sizeof(*(e->op_list)) * OP_LIST_BUFF_SIZE);
        if (!e->op_list)
            exit_error("malloc failed in add_op");
        add(e->op_list, op_code);
    }
    else
        add(e->op_list, op_code);
}