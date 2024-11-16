/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:16:46 by pleander          #+#    #+#             */
/*   Updated: 2024/11/16 13:24:50 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"
#include <iostream>

PhoneBook::PhoneBook() : next_i_{0} {}

void PhoneBook::show_contact(size_t index) {
	if (index >= N_CONTACTS) {
		std::cout << "Error: index out of range" << std::endl;
		return;
	}
	if (!this->contacts_[index].initialized) {
		std::cout << "Error: contact has not been initialized yet" << std::endl;
		return;
	}
	this->contacts_[index].print_contact();
	return;
}

void PhoneBook::show_all() {
	for (int i = 0; i < N_CONTACTS; i++) {
		if (this->contacts_[i].initialized) {
			this->contacts_[i].print_short(i, 10);
		}
	}
}

void PhoneBook::add_contact(std::string first_name, std::string last_name,
                            std::string nickname, std::string phone_number,
                            std::string darkest_secret) {
	this->contacts_[this->next_i_] =
	    Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	this->next_i_++;
	if (this->next_i_ >= N_CONTACTS) {
		this->next_i_ = 0;
	}
}
