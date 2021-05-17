NAME		=	a.out

LIBS		=	-ldl -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS	=	-Wall -Wextra -g3 -std=c++17

SRC			=	src/main.cpp	\
				src/sfml.cpp

OBJS		=	$(SRC:.cpp=.o)

CC			= c++

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LIBS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		clean fclean re all