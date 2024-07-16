/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:20:12 by seblin            #+#    #+#             */
/*   Updated: 2024/07/16 16:34:02 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (std::cerr << "need three parameters" << std::endl, (1));
	std::ifstream inf(argv[1]);
	if (!inf)
		return (std::cerr << "Error file in" << std::endl, (1));
	std::string s0 = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
		return (std::cerr << "parameter two is empty" << std::endl, (1));		
	std::ofstream ouf((s0 + ".replace").c_str());
	if (!ouf)
		return (std::cerr << "Error file out" << std::endl, (1));
	std::string line;
	while (std::getline(inf, line))
	{
		std::cout << line << std::endl;
		size_t finded;
		while ((finded = line.find(s1)) != std::string::npos)
		{
			line.erase(finded, s1.length());
			line.insert(finded, s2);
		}
		ouf << line << std::endl;			
	}	
	inf.close();
	ouf.close();	
	return (0);
}
