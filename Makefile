NAME = solong
CC = cc
SRC = main.c ft_split.c get_next_line_utils.c get_next_line.c parce_map.c ft_strlcpy.c
FLAGS = -Wall -Wextra -Werror
FLA = -lmlx -framework OpenGL -framework AppKit -g -fsanitize=address
ARG = -o

all : $(NAME)

$(NAME): $(SRC)
	$(CC)  $(FLA) $(SRC) $(ARG) solong

clean : 
	rm -f $(NAME)

fclean : clean

re: fclean all