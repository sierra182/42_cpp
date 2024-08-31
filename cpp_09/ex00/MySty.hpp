/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySty.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:36:42 by svidot            #+#    #+#             */
/*   Updated: 2024/08/31 22:06:17 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sstream>

struct MySty
{
    template <typename T>
	static void	addTest(const T & test, int endl = 1)
	{
		std::cout << std::endl << std::endl << std::endl << " ~~~~~~~~~~~~~~~";
		std::cout << "\e[1;3;90;103;9m ☣️  Test: " << test << " ☣️  \e[0m"
			<< std::endl << std::endl;
		if (endl)
			std::cout << std::endl << std::endl;
	}	

	template <typename T>
	static void addSubTest(const T & test)
	{
		std::cout << std::endl << std::endl;
		std::cout << "\t\t\t\t\t\e[1;3;90;46;9m 🥶  Subtest: " << test <<
			" 🥶  \e[0m";		
		std::cout << "~~~" << std::endl << std::endl;
	}
		
    template <typename T>
	static void addAction(const T & action)
	{
		std::cout << "\e[1;3m * " << action << "\e[0m" << std::endl;
	}

    template <typename T>
	static void addWhat(const T & what, short unsigned int color) //!cerr
	{	
		std::ostringstream oss;	
		oss << std::endl << "\e[0m";
		colorFullLine(oss.str(), color);
		oss.str("");
		oss << "\e[1;36;46m\t 🏴‍☠️   Exception: \e[1;95m"
			<< what << "   🤢 🤮  \e[0m" << std::endl;
		colorFullLine(oss.str(), color);
		oss.str("");
		oss << "\e[0m" <<  std::endl << "\e[0m";
		colorFullLine(oss.str(), color);
	}

	template <typename T>
	static void error(T what)
	{
		std::cerr << std::endl << "\e[1;31m\t 🏴‍☠️   Error: \e[1;95m"
			<< what << "   🤢 🤮\e[0m" << std::endl << std::endl;
	}

	template <typename T>
	static void colorFullLine(const T & str,
		short unsigned int color)
	{		
		struct winsize ws;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);	
		std::string empty(static_cast<int>(ws.ws_col * 0.75f), ' ');
		std::cout << "\e[4" << color << "m" << empty << "\r" << "\e[0m" <<  str << "\e[0m";// << std::endl;	
	}	
};