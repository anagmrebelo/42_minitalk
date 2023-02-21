# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arebelo <arebelo@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:23:30 by arebelo           #+#    #+#              #
#    Updated: 2022/01/31 16:45:27 by arebelo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= ./srcs/clean_struct.c ./srcs/conversions_first.c ./srcs/conversions_last.c ./srcs/conversions_main.c ./srcs/counter_funcs.c ./srcs/ft_putnbr_base_x.c ./srcs/ft_putnbr_x.c ./srcs/ft_putnbr_xu.c ./srcs/is_id.c ./srcs/libftprintf.c ./srcs/print_mfw.c ./srcs/putstr_limited.c ./srcs/print_percent.c
SRCS_BONUS 	= ./srcs/clean_struct.c ./srcs/conversions_first.c ./srcs/conversions_last.c ./srcs/conversions_main_bonus.c ./srcs/counter_funcs.c ./srcs/ft_putnbr_base_x.c ./srcs/ft_putnbr_x.c ./srcs/ft_putnbr_xu.c ./srcs/is_id.c ./srcs/libftprintf.c ./srcs/print_mfw.c ./srcs/putstr_limited.c ./srcs/print_percent.c

INCLUDE		= ./includes/libftprintf.h 

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

LIBFT_PATH	= ./libft/
LIBFT		= libft.a

NAME		= libftprintf.a

CC 			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


all:		${NAME}

${NAME}:	${OBJS}
			$(MAKE) -C ./libft all
			cp libft/libft.a ${NAME}
			@${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

bonus:		${OBJS_BONUS}
			${RM} ${NAME}
			$(MAKE) -C ./libft all
			cp libft/libft.a ${NAME}
			${AR} ${NAME} ${OBJS_BONUS}
			${RN} ${NAME}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}
			$(MAKE) -C ./libft clean

fclean:		clean
			${RM} ${NAME}
			$(MAKE) -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re
