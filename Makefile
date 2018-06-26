BIN_1 = checker
BIN_2 = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJDIR = obj/
SRCDIR = src/
INCLDIR = includes/
LIBDIR = libft/

H_FILES = push_swap.h
C_FILES_1 = moves.c \
			utils.c \
			parser.c \
			checker.c

LIBFT = $(LIBDIR)libft.a

SRC_1 = $(addprefix $(SRCDIR), $(C_FILES_1))
OBJ_1 = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC_1))))
HDRS = $(addprefix $(INCLDIR), $(H_FILES))

VPATH = $(shell find src -type d)

all: $(BIN_1)

$(BIN_1): $(OBJ_1) $(HDRS) $(LIBFT)
	@$(CC) -o $@ -L$(LIBDIR) -lft $(OBJ_1)
	@echo "\033[32;1mLinking $@\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

$(OBJDIR)%.o: %.c  $(HDRS)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< -I $(INCLDIR) $(FLAGS)
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
