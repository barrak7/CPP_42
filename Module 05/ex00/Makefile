SRC=main.cpp Bureaucrat.cpp
OBJ=$(SRC:.cpp=.o)
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
NAME=Bureaucrat

.PHONY:all re fclean clean

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all:$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all