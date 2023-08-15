NAME=phonebook
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=Contact.cpp PhoneBook.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

.PHONY=all re clean fclean

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
