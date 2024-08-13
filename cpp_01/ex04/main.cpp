/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:20:12 by seblin            #+#    #+#             */
/*   Updated: 2024/08/13 11:55:31 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <cstdlib>

int replace(char *argv[])
{
	std::ifstream inf(argv[1]);
	if (!inf)
		return (std::cerr << "Error file in" << std::endl, 1);
	std::string s0 = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
		return (std::cerr << "parameter two is empty" << std::endl, 1);		
	std::ofstream ouf((s0 + ".replace").c_str());
	if (!ouf)
		return (std::cerr << "Error file out" << std::endl, 1);
	std::cout << std::endl;
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
	std::cout << std::endl;
	system((std::string("cat ") + argv[1] + ".replace").c_str());
	std::cout << std::endl;
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (std::cerr << "need three parameters" << std::endl, 1);
	return replace(argv);
	return (0);
}
