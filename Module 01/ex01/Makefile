CXX=c++
SRC=main.cpp Zombie.cpp zombieHorde.cpp
OBJ=$(SRC:.cpp=.o)
NAME=zombieHorde
CXXFLGS=-Wall -Wextra -Werror -std=c++98

.PHONY:all re clean fclean

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