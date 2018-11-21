BIN_1     = checker
BIN_2     = push_swap

CC        = gcc
C_FLAGS   = -Wall -Wextra -Werror -g3 -fsanitize=address
LD_FLAGS  = -g3 -fsanitize=address

OBJDIR    = obj/
SRCDIR    = src/
INCLDIR   = includes/
LIBDIR    = libftprintf/

H_FILES   = common.h \
			checker.h \
			push_swap.h \
			libft.h \
			get_next_line.h \
			ft_printf.h

C_FILES_1 = checker/main_checker.c \
			parser.c \
			moves.c \
			do_op.c \
			checker/printer.c \
			checker/read_op.c \
			push_swap/utils_algo.c \
			utils.c

C_FILES_2 = push_swap/main_push_swap.c \
			parser.c \
			moves.c \
			do_op.c \
			utils.c \
			push_swap/op_orchestrator.c \
			push_swap/quick_sort.c \
			push_swap/sort_three_ints.c \
			push_swap/get_median.c \
			push_swap/utils_algo.c \
			push_swap/optimizations.c

LIBFT     = $(LIBDIR)libft.a

SRC_1     = $(addprefix $(SRCDIR), $(C_FILES_1))
OBJ_1     = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC_1))))
SRC_2     = $(addprefix $(SRCDIR), $(C_FILES_2))
OBJ_2     = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC_2))))
HDRS      = $(addprefix $(INCLDIR), $(H_FILES))

VPATH     = $(shell find $(SRCDIR) -type d)

all: $(BIN_1) $(BIN_2)

$(BIN_1): $(OBJ_1) $(HDRS) $(LIBFT)
	@$(CC) -o $@ -L$(LIBDIR) -lftprintf $(OBJ_1) $(LD_FLAGS)
	@echo "\033[32;1mLinking $@\033[0m"

$(BIN_2): $(OBJ_2) $(HDRS) $(LIBFT)
	@$(CC) -o $@ -L$(LIBDIR) -lftprintf $(OBJ_2) $(LD_FLAGS)
	@echo "\033[32;1mLinking $@\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

$(OBJDIR)%.o: %.c $(HDRS)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< -I $(INCLDIR) $(C_FLAGS)
	@echo "\033[33mCompilation $@\033[0m"

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBDIR) $@
	@echo "\033[31;1mRemove $(OBJDIR)\033[0m"

fclean: clean
	@rm -f $(BIN_1) $(BIN_2)
	@$(MAKE) -C $(LIBDIR) $@
	@echo "\033[31;1mRemove $(BIN_1) $(BIN_2)\033[0m"

re: fclean all

norm:
	@norminette $(SRCDIR) $(INCLDIR)
