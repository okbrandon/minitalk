# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 01:29:20 by bsoubaig          #+#    #+#              #
#    Updated: 2022/12/29 10:53:32 by bsoubaig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE		= \033[38;5;141m
GREEN		= \033[38;5;46m
RED			= \033[0;31m
GREY		= \033[38;5;240m
RESET		= \033[0m
BOLD		= \033[1m

NAME		= libftprintf.a

SRC_DIR		= ./srcs/
SRCS		= ft_utils.c \
			  ft_putchar.c \
			  ft_putstr.c \
			  ft_putnbr.c \
			  ft_puthexnbr.c \
			  ft_putpointer.c \
			  ft_putunsigned.c \
			  ft_parser.c \
			  ft_printf.c

OBJ_DIR		= ./objs/
OBJS		= ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}

RM			= rm -rf
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${CC} ${CFLAGS} -I${SRC_DIR} -c $< -o $@

all:			${NAME}

${NAME}:		${OBJS}
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were made ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Compiling library binaries...${GREY}"
	@ar rc ${NAME} ${OBJS}
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Library compiled ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"

${OBJS}:		| ${OBJ_DIR}

${OBJ_DIR}:
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Creating objects directory...${GREY}"
	@mkdir ${OBJ_DIR}

clean:
	@${RM} ${OBJ_DIR}
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.${GREY}"

fclean:	clean
	@${RM} ${NAME}
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"

re:	fclean all

.SILENT: all clean fclean re 
.PHONY:	all clean fclean re