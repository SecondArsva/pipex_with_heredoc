# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 20:00:17 by davidga2          #+#    #+#              #
#    Updated: 2023/09/13 00:01:26 by davidga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---VARIABLES---

# Name of the final program.
NAME = libft.a

# Source files
SRC = ft_isalpha.c				\
	  ft_memmove.c				\
	  ft_strlen.c				\
	  ft_isascii.c				\
	  ft_memset.c				\
	  ft_strncmp.c				\
	  ft_atoi.c 				\
	  ft_isdigit.c 				\
	  ft_bzero.c 				\
	  ft_isprint.c 				\
	  ft_tolower.c 				\
	  ft_isalnum.c 				\
	  ft_memcpy.c 				\
	  ft_strnstr.c 				\
	  ft_toupper.c 				\
	  ft_strlcpy.c 				\
	  ft_strlcat.c				\
	  ft_strchr.c 				\
	  ft_strrchr.c 				\
	  ft_memchr.c 				\
	  ft_memcmp.c 				\
	  ft_calloc.c 				\
	  ft_strdup.c 				\
	  ft_substr.c 				\
	  ft_strjoin.c 				\
	  ft_strtrim.c 				\
	  ft_split.c 				\
	  ft_itoa.c 				\
	  ft_strmapi.c 				\
	  ft_striteri.c				\
	  ft_putchar_fd.c			\
	  ft_putstr_fd.c 			\
	  ft_putendl_fd.c 			\
	  ft_putnbr_fd.c 			\
	  get_next_line.c 			\
	  ft_strjoin_gnl.c 			\
	  ft_printf.c 				\
	  ft_printf_utils.c			\
	  ft_matrixdup.c 			\
	  ft_free_matrix.c 			\
	  ft_print_matrix.c 		\
	  ft_printf_error.c			\
	  ft_printf_error_utils.c	\
	  ft_lstnew.c 				\
	  ft_lstadd_front.c			\
	  ft_lstsize.c				\
	  ft_lstlast.c				\
	  ft_lstadd_back.c			\
	  ft_lstdelone.c			\
	  ft_lstclear.c				\
	  ft_lstiter.c				\
	  ft_lstmap.c				\
	  ft_lstprint_str.c			\
	  ft_lstprint_int.c			\
	  ft_lstcreate.c			\
	  ft_atol.c					\
	  ft_lstprint_long.c		\
	  ft_strdoublejoin.c

# Headers like you see.
HEADERS = libft.h

# This means that OBJS are the files of SRC but changing the ".c" for ".o"
OBJS = $(SRC:%.c=%.o)

# C Compiler variable. Need a main to compile, but not with "-c", bcuz unlink.
CC = cc

# Compiler for the final program variable. Library compiler.
AR = ar

# C Compiler flags variable.
CFLAGS = -Wall -Wextra -Werror

# Compiler flags for the final program variable.
ARFLAGS = -crs

# Remove variable.
RM = rm -f

# For remove this shit.
DS = .DS_Store

# For remove the VIM weird files.
SWP = .*.swp

#---RULES---

# Main rule.
all: $(NAME)

# Rule that compiles the final programs if the ".o" exists.
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

# This rule compile the fist dependence with an output named equals to objetive
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

# PHONY rule to remove all ".o".
clean:
	$(RM) $(OBJS)

# PHONY rule to remove the final program and all the object files.
fclean: clean
	$(RM) $(NAME)

#re-make re-instal fclean delete the final program, and all call the main rule
re: fclean all

# Extra clean.
xclean:
	$(RM) $(DS) $(SWP)

# In fclean and re, we need to write the dependece on that site because isn't
# a terminal command. Because they are a rule.
# List of PHONY rules.
.PHONY: all clean fclean re xclean
