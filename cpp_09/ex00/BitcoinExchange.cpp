/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:18:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/31 09:00:21 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ){}

BitcoinExchange::~BitcoinExchange( void ){}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	*this = src;
}
BitcoinExchange & BitcoinExchange::operator=( const BitcoinExchange & )
{
	return (*this);
}

std::ostream & operator<<(std::ostream & lhs, BitcoinExchange const & rhs)
{
	lhs << "crapaud" << std::endl;
	return (lhs);
}

	