# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 13:12:30 by mmariani          #+#    #+#              #
#    Updated: 2022/02/22 11:46:01 by mmariani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRIPT_AUTHOR = trimia

NAME = libft.a

SRCS = ft_isalpha.c	\
	   ft_isdigit.c	\
	   ft_isalnum.c	\
	   ft_isascii.c	\
	   ft_isprint.c	\
	   ft_strlen.c	\
	   ft_memset.c	\
	   ft_bzero.c	\
	   ft_memcpy.c	\
	   ft_memmove.c	\
	   ft_strlcpy.c	\
	   ft_strlcat.c	\
	   ft_toupper.c	\
	   ft_tolower.c	\
	   ft_strchr.c	\
	   ft_strrchr.c	\
	   ft_strncmp.c	\
	   ft_memchr.c	\
	   ft_memcmp.c	\
	   ft_strnstr.c	\
	   ft_atoi.c	\
	   ft_calloc.c	\
	   ft_strdup.c	\
	   ft_substr.c	\
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c
OBJS = $(SRCS:.c=.o)
CC 		=	gcc
CFLAGS 	=	-Wall -Werror -Wextra -c

# BONUS = ft_lstadd_front.c	\
# 		ft_lstnew.c			\
# 		ft_lstsize.c		\
# 		ft_lstadd_back.c	\
# 		ft_lstlast.c		\
# 		ft_lstdelone.c		\
# 		ft_lstclear.c		\
# 		ft_lstclear.c		\
# 		ft_lstiter.c		\
# 		ft_lstmap.c
# OBJS_BONUS = $(BONUS:.c=.o)


all: $(NAME)

$(OBJS):
	$(CC) $(CFLAGS) $(SRCS)

$(NAME): $(OBJS)
	ar rcs libft.a $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:		fclean all

# bonus:
# 	$(CC) $(FLAGS) $(BONUS)
# 	ar -rf $(NAME) $(OBJS_BONUS)


.PHONY: all fclean re clean bonus
