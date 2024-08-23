/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:39:38 by seblin            #+#    #+#             */
/*   Updated: 2024/08/23 17:17:38 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "MyStyl.hpp"

int main ( void )
{
	std::cout << std::endl;
	MyStyl::addTest("exception bad level", 0);
	
	MyStyl::addSubTest("bad level for sign");
	
	std::cout << std::endl;
	try {
		Form form("formidable", -42, 12); }
	catch (const std::exception & e)
		{ std::cerr << e.what() << std::endl; }
		
	std::cout << std::endl;
	try	{
		Form form("formidable", 420, 12);	}
	catch (const std::exception & e)
		{ std::cerr << e.what() << std::endl; }

	MyStyl::addSubTest("bad level for execute");
		
	std::cout << std::endl;
	try {
		Form form("formidable", 42, 0);	}
	catch (const std::exception & e)
		{ std::cerr << e.what() << std::endl; }
		
	std::cout << std::endl;
	try {
		Form form("formidable", 42, 151); }
	catch (const std::exception & e)
		{ std::cerr << e.what() << std::endl; }
		
	std::cout << std::endl;
	try {
		MyStyl::addTest("increment");
		
		Form form("formidable", 15, 20);	
		std::cout << std::endl;
		Bureaucrat bur("marguerite", 16);	
		std::cout << std::endl;
			
		try	{
			bur.signForm(form); }
		catch (const std::exception & e)
		{
			std::cout << std::endl;				
			bur.incrementGrade();
			std::cout << std::endl;	
			
			try	{
				bur.signForm(form);
								
				MyStyl::addTest("copy");
							
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
		{ std::cerr << e.what() << std::endl; }

	std::cout << std::endl;
	return (0);
}