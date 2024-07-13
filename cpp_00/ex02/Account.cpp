/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:49:53 by svidot            #+#    #+#             */
/*   Updated: 2024/07/12 22:28:27 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
    : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
    (void) initial_deposit;
    this->_amount += initial_deposit;
    _totalAmount += initial_deposit; 
    _displayTimestamp();
    _accountIndex =_nbAccounts++;
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';    
    std::cout << "created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ';';
    std::cout << "amount:" << _amount << ';';  
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';';
	std::cout << "total:" << _totalAmount << ';';
	std::cout << "deposits:" << _totalNbDeposits << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
    char buffer[100];
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);
    
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", localTime);
    std::cout << buffer;
}

void	Account::makeDeposit(int deposit)
{
    (void) deposit;
    //  std::cout << "deposit:" << deposit << ';';
    this->_nbDeposits++;// += deposit;
    _totalNbDeposits++;//= deposit;
    this->_amount += deposit;
    _totalAmount += deposit;    
}

bool	Account::makeWithdrawal(int withdrawal)
{
    (void) withdrawal;
    return (true);
}

void	Account::displayStatus(void) const
{

}
