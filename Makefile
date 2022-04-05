# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekern <ekern@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 13:40:58 by ekern             #+#    #+#              #
#    Updated: 2022/04/05 13:04:21 by ekern            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
NAME = $(PUSH_SWAP)

CC = gcc
CFLAGS = -Werror -Wall -Wextra

INCLUDES = srcs/push_swap.h

LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)

SRCS = \
	srcs/push_swap.c	\
	srcs/check_error.c	\
	srcs/small_sort.c	\
	srcs/big_sort.c		\
	srcs/push.c			\
	srcs/swap.c			\
	srcs/rotate.c		\
	srcs/re_rotate.c

OBJS = ${SRCS:c=o}

all : $(LIBFT) $(NAME)

$(PUSH_SWAP) : $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_FILE) $^ -o $(NAME)

srcs/%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

big_clean : fclean $(LIBFT_FILE)_fclean

re : fclean all

# Libft

$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)

$(LIBFT_FILE)_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean

.PHONY : all clean fclean big_clean re 