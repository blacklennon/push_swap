
NAME = push_swap

CHECKER = checker

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJDIR = obj/

SRCDIR = src/

INCLDIR = includes/

LIBDIR = libft/

H_FILES = push_swap.h

C_FILES = main.c \
		  moves.c

LIBFT = $(LIBDIR)libft.a

SRC = $(addprefix $(SRCDIR), $(C_FILES))

HDRS = $(addprefix $(INCLDIR), $(H_FILES))

OBJ = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC))))

VPATH = $(shell find src -type d)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -I $(INCLDIR) -o $@ $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

$(OBJDIR)%.o: %.c  $(HDRS)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< -I $(INCLDIR) $(FLAGS)
	@echo "\033[33;32m=== Compilation $@\033[0m"

clean:
	@rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBDIR) $@
	@echo "\x1b[31m=== Remove $(OBJDIR)\033[0m"

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	$(MAKE) -C $(LIBDIR) $@
	@echo "\x1b[31m=== Remove $(NAME) $(CHECKER)\033[0m"

re: fclean all
