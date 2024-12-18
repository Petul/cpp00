/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:27:52 by pleander          #+#    #+#             */
/*   Updated: 2024/12/18 09:27:53 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
   private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;
	std::string truncate_field(std::string field, size_t fw) const;

   public:
	Contact();
	Contact(std::string first_name, std::string last_name, std::string nickname,
	        std::string phone_number, std::string darkest_secret);
	void print_contact();
	void print_short(size_t index, size_t fw);
	bool initialized;
};

#endif
