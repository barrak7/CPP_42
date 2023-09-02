CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=ClapTrap.cpp main.cpp
OBJ=ClapTrap.o main.o

.PHONY: all re fclean clean

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f a.out

re:fclean all