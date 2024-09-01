/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:47:23 by seblin            #+#    #+#             */
/*   Updated: 2024/09/01 09:33:35 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include "MySty.hpp"
#include "BitcoinExchange.hpp"

int main(int argc, char * argv[])
{
	std::cout << "\e[8;60;180t" << std::flush;
	if (argc != 2)
		return (MySty::error("we need one argument"), 1);
	errno = 0;
	std::ifstream infInp(argv[1]);	
	if (infInp.fail())	
		return MySty::error(std::string("Input File: ")
			+ std::strerror(errno)), 1;
	errno = 0;
	std::ifstream infData("data.csv");	
	if (infData.fail())	
		return MySty::error(std::string("Data File: ")
			+ std::strerror(errno)), 1;
	try {
		BitcoinExchange be(infData, infInp);
	}
	catch (std::exception const & e)
		{MySty::addWhat(e.what()); return(1);}
	std::cout << std::endl;
	return (0);
}