/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:16:10 by seblin            #+#    #+#             */
/*   Updated: 2024/08/26 15:18:39 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class BitcoinExchange
{
	BitcoinExchange( const BitcoinExchange & src );
	BitcoinExchange & operator=( const BitcoinExchange & rhs);
	
	public:
		
		BitcoinExchange( void );
		~BitcoinExchange( void );	
};