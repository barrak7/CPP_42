# include "PhoneBook.hpp"

int main() {
	std::string	option;
	PhoneBook book;
	while (1)
	{
		std::cout << "Choose an option: ";
		std::getline(std::cin, option);
		if (option.empty() && !std::cin.eof()){
			std::cout << "Available options: ADD, SEARCH, EXIT.\n";
		}
		if (option == "ADD" || option == "add")
			book.add();
		else if (option == "SEARCH" || option == "search")
			book.search();
		else if (option == "EXIT" || option == "exit" || std::cin.eof()){
			return (0);
		}
		else
			std::cout << "Invalid option!!" << std::endl;
	}
	return 0;
}
