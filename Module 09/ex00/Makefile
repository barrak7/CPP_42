SRC=main.cpp BitcoinExchange.cpp
OBJ=$(SRC:.cpp=.o)
HEADER=BitcoinExchange.hpp
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME=btc

.PHONY:all re fclean clean

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):$(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all:$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all