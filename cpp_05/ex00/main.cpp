/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:39:38 by seblin            #+#    #+#             */
/*   Updated: 2024/07/30 22:10:36 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main ( void )
{	
	std::cout << std::endl;
	try	
	{
		Bureaucrat bur("marguerite", 0);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try	
	{
		Bureaucrat bur("marguerite", 151);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		Bureaucrat bur("marguerite", 1);
		bur.decrementGrade();
		bur.decrementGrade();
		bur.incrementGrade();	
		bur.incrementGrade();	
		bur.incrementGrade();	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	try
	{
		Bureaucrat bur("marguerite", 150);
		bur.incrementGrade();	
		bur.incrementGrade();	
		bur.decrementGrade();	
		bur.decrementGrade();
		bur.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	std::cout << std::endl;
	return (0);
}