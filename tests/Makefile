SRC_DIR		=	$(realpath ../src)

SRC_FILES	=	AI.cpp		\
				Board.cpp	\
				Gomoku.cpp	\
				Tree.cpp

SRC		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC_UT	=	tests_board.cpp	\
			tests_gomoku.cpp\
			tests_ai.cpp

OBJ		=	$(SRC:%.c=%.o) $(SRC_UT:%.c=%.o)

CCTMP   =   $(SRC:%.c=%.gcno) $(SRC:%.c=%.gcda) $(SRC_UT:%.c=%.gcno) $(SRC_UT:%.c=%.gcda)

CXXFLAGS=	-Wall -Wextra --coverage -fprofile-arcs -ftest-coverage

LDFLAGS	=	-lcriterion -lgcov

RM		=	rm -rf

NAME	=	test

CC 		=	g++

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIB)
			@echo "COMPILATION COMPLETED"

clean:
			$(RM) *.gc*
			@echo "CLEAN COMPLETED"

fclean:		clean
			$(RM) $(NAME)
			@echo "FCLEAN COMPLETED"

gclean:		fclean
			$(RM) test.info
			$(RM) res

re:		 	gclean all
