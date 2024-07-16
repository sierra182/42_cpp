/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:20:12 by seblin            #+#    #+#             */
/*   Updated: 2024/07/16 14:39:38 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (std::cout << "need three parameters" << std::endl, (1));
(void) argv;
	std::ifstream inf("infile");
	if (!inf)
		return (std::cout << "Error file" << std::endl, (1));
		
	return (0);
}
