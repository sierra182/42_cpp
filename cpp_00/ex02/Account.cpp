/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:49:53 by svidot            #+#    #+#             */
/*   Updated: 2024/04/24 14:49:54 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
    (void) initial_deposit;
}

Account::~Account(void)
{
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return (1);
}

int Account::getTotalAmount(void)
{
    return (1);
}

int Account::getNbDeposits(void)
{
    return (1);
}

int Account::getNbWithdrawals(void)
{
    return (1);
}

void Account::displayAccountsInfos(void)
{
 
}


void	Account::makeDeposit(int deposit)
{
    (void) deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    (void) withdrawal;
    return (true);
}

void	Account::displayStatus( void ) const
{

}
