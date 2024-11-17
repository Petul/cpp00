#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;

Account::Account(int initial_deposit) {
  this->_amount = initial_deposit;
  this->_accountIndex = Account::_nbAccounts++;
  this->_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void) {
  this->_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";closed" << std::endl;
}

void Account::_displayTimestamp(void) {
  time_t rawtime;
  struct tm *timeinfo;
  char time_buf[16];

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(time_buf, 16, "%Y%m%d_%H%M%S", timeinfo);
  std::cout << "[" << time_buf << "] ";
}
