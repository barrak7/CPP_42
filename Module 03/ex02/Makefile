CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=ClapTrap.cpp ScavTrap.cpp main.cpp FragTrap.cpp
OBJ=ClapTrap.o main.o ScavTrap.o FragTrap.o
NAME=flap

.PHONY: all re fclean clean

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