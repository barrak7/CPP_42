#ifndef PHONE_H
# define PHONE_H

# include <iostream>
# include <cstdlib>
# include <iomanip>

class Contact {
	public:
		int			set_first(std::string name);
		std::string	get_first(void);
		int			set_last(std::string name);
		std::string get_last(void);
		int			set_nickname(std::string name);
		std::string get_nickname(void);
		int			set_number(std::string number);
		std::string get_number(void);
		void		set_secret(std::string secret);
		std::string get_secret(void);
		int			is_valid_name(std::string name);
		int			is_valid_number(std::string number);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

class PhoneBook {
	public:
		PhoneBook();
		void		add(void);
		void		search(void);
		void		show_all(void);
		void		print_contact(Contact c);
		std::string modify_str(std::string str);
		int			is_valid_number(std::string number);
	private:
		Contact		contact[8];
		int					i;
};

#endif
