# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarles <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:41:57 by pcarles           #+#    #+#              #
#    Updated: 2018/06/26 01:24:28 by pcarles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJDIR = obj/
SRCDIR = src/
INCLDIR = includes/

H_FILES = libft.h \
		  get_next_line.h
C_FILES = ft_putchar.c \
		  ft_strlen.c \
		  ft_putstr.c \
		  ft_putendl.c \
		  ft_putnbr.c \
		  ft_atoi.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memalloc.c \
		  ft_memmove.c \
		  ft_memdel.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strdup.c \
		  ft_strcpy.c \
		  ft_strncpy.c \
		  ft_strcat.c \
		  ft_strncat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strstr.c \
		  ft_strnstr.c \
		  ft_strcmp.c \
		  ft_strncmp.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strnew.c \
		  ft_strdel.c \
		  ft_strclr.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strequ.c \
		  ft_strnequ.c \
		  ft_strsub.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_strlcat.c \
		  ft_itoa.c \
		  ft_strsplit.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdel.c \
		  ft_lstadd.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_pow.c \
		  ft_islower.c \
		  ft_isupper.c \
		  get_next_line.c

SRC = $(addprefix $(SRCDIR), $(C_FILES))
HDRS = $(addprefix $(INCLDIR), $(H_FILES))
OBJ = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC))))

VPATH = $(shell find src -type d)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32;1mCreated libft/$(NAME)\033[0m"

$(OBJDIR)%.o: %.c $(HDRS)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< -I $(INCLDIR) $(FLAGS)
	@echo "\033[33mCompilation libft/$@\033[0m"

clean:
	@rm -rf $(OBJDIR)
	@echo "\033[31;1mRemove libft/$(OBJDIR)\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31;1mRemove libft/$(NAME)\033[0m"

re: fclean all
