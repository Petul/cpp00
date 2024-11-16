/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:41:05 by pleander          #+#    #+#             */
/*   Updated: 2024/11/16 13:25:35 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"
#include <iostream>

void add_contact(PhoneBook &pb) {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "First name: " << std::endl;
	std::cin >> first_name;
	std::cout << "Last name: " << std::endl;
	std::cin >> last_name;
	std::cout << "Nickname: " << std::endl;
	std::cin >> nickname;
	std::cout << "Phone number: " << std::endl;
	std::cin >> phone_number;
	std::cout << "Darkest secret: " << std::endl;
	std::cin >> darkest_secret;

	pb.add_contact(first_name, last_name, nickname, phone_number,
	               darkest_secret);
	return;
}

void search(PhoneBook &pb) {

	std::string id;

	pb.show_all();
	std::cout << "Enter index to show contact: " << std::endl;
	std::cin >> id;
	try {
		pb.show_contact((size_t)stoi(id));
	}
	catch (...) {
		std::cout << "Error: invalid index" << std::endl;
	}
	return;
}

int main(void) {
	PhoneBook pb;
	std::string option;
	while (option != "EXIT") {
		std::cout << "\nEnter ADD, SEARCH or EXIT:" << std::endl;
		std::cin >> option;
		if (std::cin.eof()) {
			return 0;
		}
		if (option == "ADD") {
			add_contact(pb);
		} else if (option == "SEARCH") {
			search(pb);
		}
	}
}
