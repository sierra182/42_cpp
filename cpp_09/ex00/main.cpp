/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:47:23 by seblin            #+#    #+#             */
/*   Updated: 2024/08/31 20:50:51 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include "MySty.hpp"
#include "BitcoinExchange.hpp"

int main(int argc, char * argv[])
{
	if (argc != 2)
		return (MySty::error("we need one argument"), 1);
	errno = 0;
	std::ifstream infInp(argv[1]);	
	if (infInp.fail())	
		return MySty::error(std::strerror(errno)), 1;
	errno = 0;
	std::ifstream infData("data.csv");	
	if (infData.fail())	
		return MySty::error(std::strerror(errno)), 1;
	try {
		BitcoinExchange be(infData, infInp);
	}
	catch (std::exception const & e)
		{MySty::addWhat(e.what(), 5); return(1);}
	std::cout << std::endl;
	return (0);
}