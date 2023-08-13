# include "Phone.hpp"

int main() {
	std::string	option;
	PhoneBook book;
	while (1)
	{
		std::cout << "Choose an option: ";
		std::getline(std::cin, option);
		std::cout << option << "\n";
		if (option.empty()){
			return 0;
		}
		if (option == "ADD")
			book.add();
		else if (option == "SEARCH")
			book.add();
		else if (option == "EXIT")
			return (0);
		else
			std::cout << "Invalid option!!" << std::endl;
	}
	return 0;
}
