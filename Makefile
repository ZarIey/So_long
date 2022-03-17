NAME 	= 	so_long
FILES	= 	so_long					\
			map_reader				\
			image_creator			\
			put_mlx					\
			errors					\
			exit					\
			movements				\
			update_map				\
			collect_exit			\
			check_square			\
			verif					\
			set_player_and_collect

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

LIBFT_DIR = ./libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g 
LIBRARIES = -lft -L$(LIBFT_DIR) -lmlx -framework OpenGL -framework AppKit
HEADERS = -I$(LIBFT_DIR) 
.c.o		:
				${CC} ${CFLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} 	:	$(LIBFT) ${OBJS}
				${CC} ${CFLAGS} ${LIBRARIES} ${OBJS} -o $@


$(LIBFT)	:	
				$(MAKE) -C $(LIBFT_DIR)

all			:	${NAME}

clean		:	
				rm -rf ${OBJS} ${OBJS_B}
				$(MAKE) clean -C $(LIBFT_DIR)

fclean 		:	clean
				rm -rf ${NAME}
				$(MAKE) fclean -C $(LIBFT_DIR)
re 			:	fclean all

.PHONY		: re all bonus clean fclean libft
