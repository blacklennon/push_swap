# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarles <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 15:03:54 by pcarles           #+#    #+#              #
#    Updated: 2018/06/04 16:34:04 by pcarles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJDIR = obj/

SRCDIR = src/

INCLDIR = includes/

LIBDIR = libft/

H_FILES = ft_printf.h \
		  libft.h \

C_FILES = ft_printf.c \
		  init_handlers.c \
		  handlers/hexa.c \
		  handlers/octal.c \
		  handlers/unsigned.c \
		  handlers/char.c \
		  handlers/int.c \
		  handlers/wchar.c \
		  handlers/pointer.c \
		  parser.c \
		  utils.c \
		  utils_2.c \
		  converter.c \

LIBFT = $(LIBDIR)libft.a

SRC = $(addprefix $(SRCDIR), $(C_FILES))

HDRS = $(addprefix $(INCLDIR), $(H_FILES))

OBJ = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC))))

VPATH = $(shell find src -type d)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cd $(OBJDIR) && ar -x ../$(LIBFT) && ar -rc ../$(NAME) *.o
	ranlib $(NAME)

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
	@rm -f $(NAME) test
	$(MAKE) -C $(LIBDIR) $@
	@echo "\x1b[31m=== Remove $(NAME) test\033[0m"

re: fclean all
