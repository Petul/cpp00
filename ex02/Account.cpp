/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleander <pleander@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:57:15 by pleander          #+#    #+#             */
/*   Updated: 2024/12/18 10:36:09 by pleander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	          << ";created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	          << ";closed" << std::endl;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
	          << ";deposits:" << this->_nbDeposits
	          << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::makeDeposit(int deposit)
{
	if (deposit < 0)
	{
		std::cout << "refused" << std::endl;
		return;
	}
	int p_amount = this->checkAmount();
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
	          << ";deposit:" << deposit << ";amount:" << this->checkAmount()
	          << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	int p_amount = this->checkAmount();
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
	          << ";withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->checkAmount()
	          << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

void Account::_displayTimestamp(void)
{
	time_t rawtime;
	struct tm *timeinfo;
	char time_buf[16];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(time_buf, 16, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << time_buf << "] ";
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
	          << ";total:" << Account::getTotalAmount()
	          << ";deposits:" << Account::getNbDeposits()
	          << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}
