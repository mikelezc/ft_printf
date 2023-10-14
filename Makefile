# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 07:56:02 by mlezcano          #+#    #+#              #
#    Updated: 2023/10/13 19:32:16 by mlezcano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables 

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
LIB 		= ar rcs
OBJ			= $(SRC:.c=.o)
RM			= rm -rf

#Sources

SRC	=			ft_printf.c\
				ft_alpha.c\
				ft_numeric.c\

###

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -c $(CFLAGS) $(SRC)
			$(LIB) $(NAME) $(OBJ)


clean:
			@$(RM) *.o

fclean:		clean
			@$(RM) -f $(NAME)
			
re:			fclean all
			
.PHONY:		all, clean, fclean, re
