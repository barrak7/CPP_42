# include "Phone.hpp"

int PhoneBook::i = 0;

int PhoneBook::is_valid_name(std::string name)
{
	for (size_t j = 0; j < name.length(); j++){
		if (!std::isalpha(name[j]) && !std::isspace(name[j]))
			return (0);
	}
	return (1);
}

int PhoneBook::is_valid_number(std::string number)
{
	for (size_t j = 0; j < number.length(); j++){
		if (!std::isdigit(number[j]) && !std::isspace(number[j]))
			return (0);
	}
	return (1);
}

void PhoneBook::add(void) {
	/* -- First Name -- */
	std::string prompt;
	std::cout << "Enter First Name: ";
	std::getline(std::cin, prompt);
	while (!is_valid_name(prompt)){
		std::cout << "First name can only contain alphabets!!" << std::endl;
		std::cout << "Enter First Name: ";
		std::getline(std::cin, prompt);
	}
	contact[i % 8].set_first(prompt);

	/* -- Last Name -- */
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, prompt);
	while (!is_valid_name(prompt)){
		std::cout << "Last name can only contain alphabets!!" << std::endl;
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, prompt);
	}
	contact[i % 8].set_last(prompt);

	/* -- Nickname -- */
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, prompt);
	while (!is_valid_name(prompt)){
		std::cout << "Nickname can only contain alphabets!!" << std::endl;
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, prompt);
	}
	contact[i % 8].set_nickname(prompt);

	/* -- Phone Number -- */
	std::cout << "Enter Phone number: ";
	std::getline(std::cin, prompt);
	while (!is_valid_number(prompt)){
		std::cout << "Phone number can only contain digits!!" << std::endl;
		std::cout << "Enter Phone number: ";
		std::getline(std::cin, prompt);
	}
	contact[i % 8].set_number(prompt);

	/* -- Darkest Secret -- */
	std::cout << "Enter Darkest secret: ";
	std::getline(std::cin, prompt);
	while (prompt.empty()){
		std::cout << "Field can't be empty!!" << std::endl;
		std::cout << "Enter Darkest secrect: ";
		std::getline(std::cin, prompt);
	}
	contact[i % 8].set_secret(prompt);
}
