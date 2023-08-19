CXX=c++
SRC=newZombie.cpp randomChump.cpp Zombie.cpp main.cpp
OBJ=$(SRC:.cpp=.o)
NAME=zombie
CXXFLAGS=-Wall -Wextra -Werror -std=c++98

.PHONY:all fclean clean re

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