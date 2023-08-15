#include "PhoneBook.hpp"

int Contact::is_valid_name(std::string name)
{
	if (std::cin.eof()){
		std::cout << std::endl;
		std::exit(0);
	}
	for (size_t j = 0; j < name.length(); j++){
		if (!std::isalpha(name[j]) && !std::isspace(name[j]))
			return (0);
	}
	return (1);
}

int Contact::is_valid_number(std::string number)
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

int Contact::set_first(std::string name){
	if (!is_valid_name(name)){
		std::cout << "First name can only contain alphabets!!" << std::endl;
		return 0;
	}
	first_name = name;
	return 1;
}

std::string Contact::get_first(void){
	return (first_name);
}

int Contact::set_last(std::string name){
	if (!is_valid_name(name)){
		std::cout << "Last name can only contain alphabets!!" << std::endl;
		return 0;
	}
	Contact::last_name = name;
	return 1;
}

std::string Contact::get_last(void){
	return (last_name);
}

int Contact::set_nickname(std::string name){
	if (!is_valid_name(name)){
		std::cout << "Nickname can only contain alphabets!!" << std::endl;
		return 0;
	}
	Contact::nickname = name;
	return 1;
}

std::string Contact::get_nickname(void){
	return (nickname);
}

int Contact::set_number(std::string number){
	if (!is_valid_number(number)){
		std::cout << "Phone number can only contain digits!!" << std::endl;
		return (0);
	}
	Contact::phone_number = number;
	return 1;
}

std::string Contact::get_number(void){
	return (first_name);
}

void Contact::set_secret(std::string secret){
	Contact::darkest_secret = secret;
}

std::string Contact::get_secret(void){
	return (darkest_secret);
}