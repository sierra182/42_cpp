/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:18:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/31 09:22:28 by seblin           ###   ########.fr       */
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
	// for (std::map<std::string, float>::iterator it = inputMap.begin(); it != inputMap.end(); it++)
	// 	std::cout << "map: " << it->first << " : " << it->second << std::endl;

	// std::cout << "****************" << std::endl;	
	// for (std::map<std::string, float>::iterator it = dataMap.begin(); it != dataMap.end(); it++)
	// 	std::cout << "data: " << it->first << " : " << it->second << std::endl;
	lhs << "crapaud" << std::endl;
	return (lhs);
}

	