#include "Phone.hpp"

void Contact::set_first(std::string name){
	Contact::first_name = name;
}
void Contact::set_last(std::string name){
	Contact::last_name = name;
}
void Contact::set_nickname(std::string name){
	Contact::nickname = name;
}
void Contact::set_number(std::string number){
	Contact::phone_number = number;
}
void Contact::set_secret(std::string secret){
	Contact::darkest_secret = secret;
}
