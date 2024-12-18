/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:20:11 by pleander          #+#    #+#             */
/*   Updated: 2024/12/18 09:48:06 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

#include <iomanip>
#include <iostream>

Contact::Contact() : initialized{false}
{
}

Contact::Contact(std::string first_name, std::string last_name,
                 std::string nickname, std::string phone_number,
                 std::string darkest_secret)
    : first_name_{first_name},
      last_name_{last_name},
      nickname_{nickname},
      phone_number_{phone_number},
      darkest_secret_{darkest_secret},
      initialized{true}
{
}

void Contact::print_contact()
{
	std::cout << "First name: " << this->first_name_ << "\n"
	          << "Last name: " << this->last_name_ << "\n"
	          << "Nickname: " << this->nickname_ << "\n"
	          << "Phone number: " << this->phone_number_ << "\n"
	          << "Darkest secret: " << this->darkest_secret_ << std::endl;
}

void Contact::print_short(size_t index, size_t fw)
{
	std::cout << std::setw(fw) << index << "|" << std::setw(fw)
	          << this->truncate_field(this->first_name_, fw) << "|"
	          << std::setw(fw) << this->truncate_field(this->last_name_, fw)
	          << "|" << std::setw(fw)
	          << this->truncate_field(this->nickname_, fw) << std::endl;
}

std::string Contact::truncate_field(std::string field, size_t fw) const
{
	if (field.size() <= fw)
	{
		return (field);
	}
	std::string truncated = field.substr(0, fw);
	truncated[fw - 1] = '.';
	return (truncated);
}
