# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjales <mjales@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:25:22 by mjales            #+#    #+#              #
#    Updated: 2022/04/02 14:35:00 by mjales           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
LIB2	= ranlib
RM				= /bin/rm -f

NAME	= libftprintf.a

INCLUDE = ft_printf.h
SRCS	= ft_printf.c ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

all: 		$(NAME) clean

$(NAME): $(OBJS) $(INCLUDE)
				$(LIB1) $(NAME) $(OBJS)
				$(LIB2) $(NAME)

bonus:		$(NAME) clean

.c.o:
					$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)
clean:
					$(RM) $(OBJS)
fclean: 	clean
					$(RM) $(NAME)

re: 				fclean all

.PHONY:		all clean fclean re