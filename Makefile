BIN_1 = checker
BIN_2 = push_swap

CC = gcc
C_FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LD_FLAGS = -g3 -fsanitize=address

OBJDIR = obj/
SRCDIR = src/
INCLDIR = includes/
LIBDIR = libft/

H_FILES = push_swap.h
C_FILES_1 = checker.c \
			parser.c \
			moves.c \
			do_op.c \
			utils.c \
			utils_algo.c

C_FILES_2 = push_swap.c \
			parser.c \
			moves.c \
			utils.c \
			algo/utils_algo.c \
			algo/general_algo.c \
			algo/median_sort.c \
			algo/sort.c

LIBFT = $(LIBDIR)libft.a

SRC_1 = $(addprefix $(SRCDIR), $(C_FILES_1))
OBJ_1 = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC_1))))
SRC_2 = $(addprefix $(SRCDIR), $(C_FILES_2))
OBJ_2 = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC_2))))
HDRS = $(addprefix $(INCLDIR), $(H_FILES))

VPATH = $(shell find $(SRCDIR) -type d)

all: $(BIN_1) $(BIN_2)

$(BIN_1): $(OBJ_1) $(HDRS) $(LIBFT)
	@$(CC) -o $@ -L$(LIBDIR) -lft $(OBJ_1) $(LD_FLAGS)
	@echo "\033[32;1mLinking $@\033[0m"

$(BIN_2): $(OBJ_2) $(HDRS) $(LIBFT)
	@$(CC) -o $@ -L$(LIBDIR) -lft $(OBJ_2) $(LD_FLAGS)
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
