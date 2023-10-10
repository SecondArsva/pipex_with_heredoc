# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 17:34:05 by davidga2          #+#    #+#              #
#    Updated: 2023/09/28 20:20:00 by davidga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC = src/pipex.c		\
	  src/childs.c		\
	  src/ft_error.c	\
	  src/ft_exec.c
OBJS = $(SRC:%.c=%.o)

SRC_BONUS = bonus/pipex_bonus.c		\
	  		bonus/childs_bonus.c		\
	  		bonus/ft_error_bonus.c	\
	  		bonus/ft_exec_bonus.c
OBJS_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(SRC) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(SRC_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
