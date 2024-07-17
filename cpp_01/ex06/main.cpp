/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 07:58:39 by seblin            #+#    #+#             */
/*   Updated: 2024/07/17 11:48:10 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <ostream>

int	main( int argc, char *argv[])
{
	if (argc != 2)
		return (std::cerr << "Bad argument number!" << std::endl, 1);
	std::string level(argv[1]);
	if (level.empty())
		return (std::cerr << "Empty arg!" << std::endl, 1);	
	Harl harl;
	harl.complain(level);	
	return (0);
}