# include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	i = 0;
}

int PhoneBook::is_valid_number(std::string number)
{
	if (std::cin.eof()){
		std::cout << std::endl;
		std::exit(0);
	}
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
	while (!contact[i % 8].set_first(prompt)){
		std::cout << "Enter First Name: ";
		std::getline(std::cin, prompt);
	}

	/* -- Last Name -- */
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, prompt);
	while(!contact[i % 8].set_last(prompt)){
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, prompt);
	};
	
	/* -- Nickname -- */
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, prompt);
	while (!contact[i % 8].set_nickname(prompt)){
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, prompt);
	}	

	/* -- Phone Number -- */
	std::cout << "Enter Phone number: ";
	std::getline(std::cin, prompt);
	while (!contact[i % 8].set_number(prompt)){
		std::cout << "Enter Phone number: ";
		std::getline(std::cin, prompt);
	}

	/* -- Darkest Secret -- */
	std::cout << "Enter Darkest secret: ";
	std::getline(std::cin, prompt);
	if (std::cin.eof()){
		std::cout << std::endl;
		std::exit(0);
	}
	while (prompt.empty()){
		std::cout << "Field can't be empty!!" << std::endl;
		std::cout << "Enter Darkest secrect: ";
		std::getline(std::cin, prompt);
	}
	contact[i % 8].set_secret(prompt);
	i++;
}

void PhoneBook::print_contact(Contact c){
	std::cout << "First Name    : " << c.get_first() << std::endl;
	std::cout << "Last Name     : " << c.get_last() << std::endl;
	std::cout << "Nickname      : " << c.get_nickname() << std::endl;
	std::cout << "Phone Number  : " << c.get_number() << std::endl;
	std::cout << "Dark Secret   : " << c.get_secret() << std::endl;
}

std::string PhoneBook::modify_str(std::string str){
	std::string test;

	test = str;
	if (test.length() > 9){
		test[9] = '.';
		test.resize(10);
	}
	return (test);
}

void PhoneBook::show_all(void){
	std::cout << std::string(45, '-') << "\n";
	std::cout << "|" << "        ID" << "|" << "First Name" << "|";
	std::cout << " Last Name" << "|" << "  Nickname" << "|\n";
	std::cout << std::string(45, '-') << "\n";
	for (int i = 0; i < 8 && i < PhoneBook::i; i++){
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i + 1 << "|";
		std::cout << std::setw(10);
		std::cout << modify_str(contact[i].get_first()) << "|";
		std::cout << std::setw(10);
		std::cout << modify_str(contact[i].get_last()) << "|";
		std::cout << std::setw(10);
		std::cout << modify_str(contact[i].get_nickname()) << "|\n";
		std::cout << std::string(45, '-') << "\n";
	}
}

void PhoneBook::search(void){
	std::string input;
	int 		id;

	show_all();
	std::cout << "Enter contact ID: ";
	std::getline(std::cin, input);
	if (!is_valid_number(input)){
		std::cout << "Id must be a number!\n";
		return ;
	}
	id = std::atoi(input.c_str());
	if (id < 1 || id > 8){
		std::cout << "Id is out of range!\n";
		return ;
	}
	if (id > i){
		std::cout << i << "\n";
		std::cout << "contact doesn't exist!\n";
		return ;
	}
	print_contact(contact[id - 1]);
}