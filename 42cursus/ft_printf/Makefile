# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 16:46:20 by mmariani          #+#    #+#              #
#    Updated: 2022/05/09 11:15:16 by mmariani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRIPT_AUTHOR = trimia

NAME = libft_printf.a

LIBFT_DIR = ../libft/Makefile

SRCS = 
OBJS = $(SRCS:.c=.o)

CC 		=	gcc

CFLAGS 	=	-Wall -Werror -Wextra -c

BONUS =	

OBJS_BONUS = $(BONUS:.c=.o)


all: $(NAME)

$(MAKE):
	make -C LIBFT_DIR 

$(OBJS):
	$(CC) $(CFLAGS) $(SRCS)

$(OBJS_BONUS):
	$(CC) $(CFLAGS) $(BONUS)

$(NAME): $(OBJS)
	ar rcs libft.a $(OBJS)
	# ranlib $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re:		fclean all

bonus: $(OBJS_BONUS)
	ar rcs libft.a $(OBJS_BONUS)


.PHONY: all fclean re clean bonus 