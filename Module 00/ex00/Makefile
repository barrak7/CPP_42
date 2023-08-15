NAME=megaphone
CXX=c++
CXXLAGS=-Wall -Wextra -Werror -std=c++98
SRC=megaphone.cpp
OBJ=$(SRC:.cpp=.o)

.PHONY= all clean fclean re

%.o:%.cpp
	$(CXX) $(CXXLAGS) -c $< -o $@

$(NAME):$(OBJ)
	$(CXX) $(CXXLAGS) $(OBJ) -o $(NAME)

all:$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all
