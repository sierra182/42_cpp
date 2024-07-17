/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 07:58:33 by seblin            #+#    #+#             */
/*   Updated: 2024/07/17 10:28:47 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	this->action[0] = &Harl::debug;
	this->action[1] = &Harl::info;
	this->action[2] = &Harl::warning;
	this->action[3] = &Harl::error;
	this->action[4] = &Harl::badLevel;
	this->mapping[0] = "DEBUG";
	this->mapping[1] = "INFO";
	this->mapping[2] = "WARNING";
	this->mapping[3] = "ERROR";
	this->mapping[4] = "NOWAY";
}

void	Harl::complain( std::string level ) const
{
	int i;
	
	for (i = 0; i < 4 && this->mapping[i] != level; i++)	
		;
	(this->*action[i])();
}

void	Harl::debug( void ) const
{
	std::cout <<"DEBUG - " "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void	Harl::info( void ) const
{
	std::cout << "INFO - " "I cannot believe adding extra bacon costs more"
		"money. You didn’t put enough bacon in my burger! If you did,"
		" I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void ) const
{
	std::cout << "WARNING - " "I think I deserve to have some extra"
		" bacon for free. I’ve been coming for years whereas you started"
		" working here since last month." << std::endl;
}

void	Harl::error( void ) const
{
	std::cout << "ERROR - " "This is unacceptable! I want to speak to the"
		" manager now."	<< std::endl;
}

void	Harl::badLevel( void ) const
{
	std::cerr << "level does not exist! use DEBUG / INFO / WARNING / ERROR"
		<< std::endl;
}