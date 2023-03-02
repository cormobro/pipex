SRCS = $(addprefix Sources/, pipex.c pipex_utils.c ft_split.c)

NAME = pipex

INC = -I ./

FLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

${NAME} : ${OBJS}
			gcc ${FLAGS} ${INC} $(OBJS) -o $(NAME)

all : ${NAME}

%.o:%.c
		gcc ${FLAGS} -c $< -o $@

clean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re NAME
