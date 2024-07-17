/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 07:58:33 by seblin            #+#    #+#             */
/*   Updated: 2024/07/17 11:47:26 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
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
	switch (i)
	{
		case 0:				
			this->debug(); 
			// Intentionally fall through
		case 1:
			this->info();
			// Intentionally fall through
		case 2:
			this->warning();
			// Intentionally fall through
		case 3:
			this->error();
			break;
		default:
			this->badLevel();
	}			
}

void	Harl::debug( void ) const
{
	std::cout <<"[DEBUG] \n " "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-special-ketchup burger."
		" I really do!\n" << std::endl;
}

void	Harl::info( void ) const
{
	std::cout << "[INFO] \n " "I cannot believe adding extra bacon costs more"
		"money. You didn’t put enough bacon in my burger! If you did,"
		" I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning( void ) const
{
	std::cout << "[WARNING] \n " "I think I deserve to have some extra"
		" bacon for free. I’ve been coming for years whereas you started"
		" working here since last month.\n" << std::endl;
}

void	Harl::error( void ) const
{
	std::cout << "[ERROR] \n " "This is unacceptable! I want to speak to the"
		" manager now.\n"	<< std::endl;
}

void	Harl::badLevel( void ) const
{
	std::cerr << "[ Probably complaining about insignificant problems ]"
		<< std::endl;
}