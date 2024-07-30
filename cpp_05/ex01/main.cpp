/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:39:38 by seblin            #+#    #+#             */
/*   Updated: 2024/07/30 13:02:59 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

int main (void )
{
	std::cout << std::endl;
	try 
	{
		Form form("formidable", -42, 12);		
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try 
	{
		Form form("formidable", 420, 12);		
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try 
	{
		Form form("formidable", 42, 0);		
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try 
	{
		Form form("formidable", 42, 151);		
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try 
	{
		Form form("formidable", 15, 20);	
		std::cout << std::endl;
		Bureaucrat bur("marguerite", 16);	
		std::cout << std::endl;		
		try
		{
			bur.signForm(form);		
		}
		catch (const std::exception & e)
		{
			std::cout << std::endl;				
			bur.incrementGrade();
			std::cout << std::endl;	
			
			try
			{
				bur.signForm(form);
				std::cout << std::endl;
				std::cout << form;
				std::cout << std::endl;		
				Form form2("formol", 1, 1);
				std::cout << std::endl;
				std::cout << " *copy formidable to formol*" << std::endl;
				form2 = form;
				std::cout << std::endl;
				std::cout << form2;	
			}
			catch (const std::exception & e)
			{
				std::cout << std::endl;	
				std::cerr << e.what() << std::endl;
				bur.incrementGrade();				
			}
		}
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	return (0);
}