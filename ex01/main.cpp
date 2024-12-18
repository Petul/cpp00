/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:41:05 by pleander          #+#    #+#             */
/*   Updated: 2024/12/18 09:40:05 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "phonebook.hpp"

std::string get_input(std::string msg)
{
	std::string input;

	if (msg != "") std::cout << msg << ": " << std::endl;
	std::getline(std::cin, input);
	return (input);
}

void add_contact(PhoneBook &pb)
{
	std::string first_name = get_input("First name");
	std::string last_name = get_input("Last name");
	std::string nickname = get_input("Nickname");
	std::string phone_number = get_input("Phone number");
	std::string darkest_secret = get_input("Darkest secret");
	pb.add_contact(first_name, last_name, nickname, phone_number,
	               darkest_secret);
	return;
}

void search(PhoneBook &pb)
{
	std::string id;

	pb.show_all();
	id = get_input("Enter index to show contact");
	try
	{
		pb.show_contact((size_t)stoi(id));
	}
	catch (...)
	{
		std::cout << "Error: invalid index" << std::endl;
	}
	return;
}

int main(void)
{
	PhoneBook pb;
	std::string option;
	while (option != "EXIT" && !std::cin.eof())
	{
		option = get_input("\nEnter ADD, SEARCH or EXIT");
		if (option == "ADD")
		{
			add_contact(pb);
		}
		else if (option == "SEARCH")
		{
			search(pb);
		}
	}
}
