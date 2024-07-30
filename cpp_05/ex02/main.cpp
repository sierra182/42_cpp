/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:39:38 by seblin            #+#    #+#             */
/*   Updated: 2024/07/30 22:12:09 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ( void )
{
	std::cout << "truc" << std::endl;
	PresidentialPardonForm form("jhon");
	RobotomyRequestForm rob("zorg");
	RobotomyRequestForm rob2("zoé");
	RobotomyRequestForm rob3("zara");
	RobotomyRequestForm rob4("zirk");
	ShrubberyCreationForm shrub("boumbo");
	// Bureaucrat bur("marguerite", 16);
	// bur.signForm(form);
	// std::cout << form << std::endl;
	// PresidentialPardonForm form2("24target");
	// std::cout << form2 << std::endl;
	// form2 = form;
	// std::cout << form2 << std::endl;


	// try 
	// {
	// 	Form form("formidable", -42, 12);		
	// }
	// catch (const std::exception & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << std::endl;
	// try 
	// {
	// 	Form form("formidable", 420, 12);		
	// }
	// catch (const std::exception & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << std::endl;
	// try 
	// {
	// 	Form form("formidable", 42, 0);		
	// }
	// catch (const std::exception & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << std::endl;
	// try 
	// {
	// 	Form form("formidable", 42, 151);		
	// }
	// catch (const std::exception & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << std::endl;
	// try 
	// {
	// 	Form form("formidable", 15, 20);	
	// 	std::cout << std::endl;
	// 	Bureaucrat bur("marguerite", 16);	
	// 	std::cout << std::endl;		
	// 	try
	// 	{
	// 		bur.signForm(form);		
	// 	}
	// 	catch (const std::exception & e)
	// 	{
	// 		std::cout << std::endl;				
	// 		bur.incrementGrade();
	// 		std::cout << std::endl;	
			
	// 		try
	// 		{
	// 			bur.signForm(form);
	// 			std::cout << std::endl;
	// 			std::cout << form;
	// 			std::cout << std::endl;		
	// 			Form form2("formol", 1, 1);
	// 			std::cout << std::endl;
	// 			std::cout << " *copy formidable to formol*" << std::endl;
	// 			form2 = form;
	// 			std::cout << std::endl;
	// 			std::cout << form2;	
	// 		}
	// 		catch (const std::exception & e)
	// 		{
	// 			std::cout << std::endl;	
	// 			std::cerr << e.what() << std::endl;
	// 			bur.incrementGrade();				
	// 		}
	// 	}
	// }
	// catch (const std::exception & e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	std::cout << std::endl;
	return (0);
}