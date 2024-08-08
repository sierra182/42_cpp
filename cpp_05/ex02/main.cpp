/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:39:38 by seblin            #+#    #+#             */
/*   Updated: 2024/08/08 14:43:27 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ( void )
{	
	std::cout << std::endl;
	std::string shrubName = "christmasTree";
	try {		
		PresidentialPardonForm pres("cypher");
		RobotomyRequestForm rob("zorg");
		ShrubberyCreationForm shrub(shrubName);
		
		Bureaucrat bur("marguerite", 73);
		Bureaucrat bur2("marge", 46);
	
		bur.executeForm(rob);	
		bur2.signForm(rob);	
		bur2.executeForm(rob);		
		std::cout <<std::endl;
		bur2.incrementGrade();
		std::cout <<std::endl;		
		bur2.executeForm(rob);
		bur.executeForm(pres);
		bur.signForm(pres);
		Bureaucrat homer_bur("homer", 1);
		homer_bur.signForm(pres);
		bur.executeForm(pres);
		std::cout <<std::endl;
		homer_bur.executeForm(pres);
		homer_bur.executeForm(shrub);
		bur.signForm(shrub);
		bur.executeForm(shrub);	
	}
	catch (const std::exception &e)
		{ std::cerr << e.what() << std::endl; }
		
	system(("cat " +  shrubName + "_shrubbery").c_str());
	std::cout <<std::endl;
	return (0);
}