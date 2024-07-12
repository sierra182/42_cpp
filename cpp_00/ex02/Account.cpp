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

Account::Account(int initial_deposit)
{
    (void) initial_deposit;
    _displayTimestamp();
    std::cout << "created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
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
}

bool	Account::makeWithdrawal(int withdrawal)
{
    (void) withdrawal;
    return (true);
}

void	Account::displayStatus(void) const
{

}
