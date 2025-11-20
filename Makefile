# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sara <sara@student.42madrid.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 14:00:00 by sara              #+#    #+#              #
#    Updated: 2025/10/05 15:00:00 by sara             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------
#   VARIABLES
# ------------------------
NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

# ------------------------
#   LIBFT
# ------------------------
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# ------------------------
#   SOURCES & OBJECTS
# ------------------------
SRCS        = $(wildcard *.c) $(wildcard */*.c)
OBJS        = $(SRCS:.c=.o)

# ------------------------
#   RULES
# ------------------------
all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
