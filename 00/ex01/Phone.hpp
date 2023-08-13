#ifndef PHONE_H
# define PHONE_H

# include <iostream>

class Contact {
	public:
		bool initialized;
		void set_first(std::string name);
		void set_last(std::string name);
		void set_nickname(std::string name);
		void set_number(std::string number);
		void set_secret(std::string secret);
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

class PhoneBook {
	public:
		void	add(void);
		void	search(void);
		int		is_valid_name(std::string name);
		int		is_valid_number(std::string number);
	private:
		Contact		contact[8];
		static int	i;
};

#endif
