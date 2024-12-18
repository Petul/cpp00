/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:55:59 by pleander          #+#    #+#             */
/*   Updated: 2024/11/15 13:08:25 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			std::cout << (char)std::toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
