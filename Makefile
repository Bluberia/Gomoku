NAME 	= 	pbrain-gomoku-ai

SRC 	=	src/main.cpp	\
			src/Gomoku.cpp	\
			src/Tree.cpp	\
			src/Board.cpp	\
			src/AI.cpp

CXXFLAGS=	-W -Wall -Wextra

OBJ 	= 	$(SRC:%.cpp=%.o)

LDFLAGS =

CXX 	=	g++

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ)
			@echo "COMPILATION COMPLETED"


clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re: 		fclean all

tests_run:
			$(MAKE) -C ./tests
			./tests/test --verbose


debug:		CFLAGS += -g
debug:		re