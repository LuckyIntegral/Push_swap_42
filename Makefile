CC		= cc
CFLAGS	= -Wall -Werror -Wextra

NAME	= push_swap

LIBDIR	= ./libft
LIBFT	= ${LIBDIR}/libftprintf.a

DIR	= mandatory

SRCS	= \
		${DIR}/ps_push.c \
		${DIR}/ps_reverse_rotate.c \
		${DIR}/ps_rotate.c \
		${DIR}/ps_swap.c \
		${DIR}/ft_errors.c \
		${DIR}/ft_parser.c \
		${DIR}/ft_utils.c \
		${DIR}/ft_hardcode_cases.c \
		${DIR}/ft_stage_1.c \
		${DIR}/ft_stage_2.c \
		${DIR}/ft_stage_3.c \
		${DIR}/main.c

OBJS	= ${SRCS:.c=.o}

${NAME}	: ${LIBFT} ${OBJS}
		${CC} -o $@ ${OBJS} -L . ./libft/libftprintf.a

%.o		: %.c
		${CC} ${CFLAGS} -c $< -o $@ -I .

all		: ${NAME}

${LIBFT}:
		make --no-print-directory -C $(LIBDIR) all

clean	:
		make --no-print-directory -C ${LIBDIR} clean
		rm -f ${OBJS}

fclean	: clean
		make --no-print-directory -C ${LIBDIR} fclean
		rm -f ${NAME}

re		: fclean all

reb		: fclean bonus

.PHONY: all, bonus, clean, fclean, re
