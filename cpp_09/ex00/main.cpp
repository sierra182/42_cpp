/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:47:23 by seblin            #+#    #+#             */
/*   Updated: 2024/08/26 19:21:37 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include "MyStyl.hpp"

int main(int argc, char * argv[])
{
	if (argc != 2)
		return (MyStyl::error("we need one argument"), 1);
	errno = 0;
	std::ifstream inf(argv[1]);	
	if (inf.fail())	
		MyStyl::error(std::strerror(errno));
	
	std::string line;		
	while (std::getline(inf, line))
	{
		std::cout << line << std::endl;
		line.find()
		
	}	
		
	
	(void) argc, (void) argv;
	return (0);
}