/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:01:55 by svidot            #+#    #+#             */
/*   Updated: 2024/09/01 21:13:44 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "MySty.hpp"

int main(int argc, char * argv[])
{
	if (argc <= 1) 
        return (MySty::error("we need at least one argument"), 1); //? one or two ...
	
	try {
		PmergeMe pm(*++argv);
	}
	catch (std::exception const & e)
		{ MySty::addWhat(e.what()); }    
    return (0);
}
