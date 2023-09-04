CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp Fixed.cpp
OBJ=main.o Fixed.o
NAME=Fixed

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