/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:39:38 by seblin            #+#    #+#             */
/*   Updated: 2024/07/30 11:36:41 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

int main (void )
{
	try 
	{
		Form form("formidable", -42, 12);		
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		Form form("formidable", 420, 12);		
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		Form form("formidable", 42, 0);		
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		Form form("formidable", 42, 151);		
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		Form form("formidable", 15, 20);
		Bureaucrat bur("marguerite", 16);		
		try
		{
			bur.signForm(form);		
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;		
			bur.incrementGrade();		
			try
			{
				bur.signForm(form);		
			}
			catch (const std::exception & e)
			{
				std::cerr << e.what() << std::endl;
				bur.incrementGrade();				
			}
		}
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	
	// std::cout << std::endl;
	// try	
	// {
	// 	Bureaucrat bur("marguerite", 0);
	// }
	// catch (const std::exception & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	
	// std::cout << std::endl;
	// try	
	// {
	// 	Bureaucrat bur("marguerite", 151);
	// }
	// catch (const std::exception & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	
	// std::cout << std::endl;
	// try
	// {
	// 	Bureaucrat bur("marguerite", 1);
	// 	bur.decrementGrade();
	// 	bur.decrementGrade();
	// 	bur.incrementGrade();	
	// 	bur.incrementGrade();	
	// 	bur.incrementGrade();	
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// std::cout << std::endl;
	// try
	// {
	// 	Bureaucrat bur("marguerite", 150);
	// 	bur.incrementGrade();	
	// 	bur.incrementGrade();	
	// 	bur.decrementGrade();	
	// 	bur.decrementGrade();
	// 	bur.decrementGrade();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }	
	std::cout << std::endl;
	return (0);
}