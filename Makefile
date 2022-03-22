# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 13:40:58 by ekern             #+#    #+#              #
#    Updated: 2022/03/22 16:38:11 by ekern            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

NAME = $(PUSH_SWAP)

CC = gcc

MLXFLAGS = -Lmlx -lmlx -framework AppKit -framework OpenGL

INCLUDES = srcs/push_swap.h

LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)

SRCS = \
	srcs/push_swap.c	\
	srcs/check_error.c	\
	srcs/small_sort.c	\
	srcs/big_sort.c		\

OBJS = ${SRCS:c=o}

all : $(LIBFT_FILE) $(NAME)

$(PUSH_SWAP) : $(OBJS)
	$(CC) $(LIBFT_FILE) $^ -o $(NAME)

srcs/%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

big_clean : fclean $(LIBFT)_fclean

re : fclean all

# Libft

$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)

$(LIBFT_FILE)_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean

.PHONY : all clean fclean big_clean re 