/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:56:39 by pleander          #+#    #+#             */
/*   Updated: 2024/12/18 09:53:24 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define N_CONTACTS 8

#include "contact.hpp"

class PhoneBook
{
   public:
	PhoneBook();
	void show_contact(size_t index);
	void show_all();
	void add_contact(std::string first_name, std::string last_name,
	                 std::string nickname, std::string phone_number,
	                 std::string darkest_secret);

   private:
	size_t next_i_;
	Contact contacts_[N_CONTACTS];
};

#endif
