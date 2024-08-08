/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:39:38 by seblin            #+#    #+#             */
/*   Updated: 2024/08/08 14:44:18 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int main ( void )
{	
	try {	
		std::cout << std::endl;
		Intern someRandomIntern;
		AForm* rrf; //? Form *
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat bur("homer", 1);
		bur.executeForm(*rrf);
		bur.signForm(*rrf);
		bur.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		bur.signForm(*rrf);
		bur.executeForm(*rrf);
		delete rrf;
		std::string shrubName = "Bender";
		rrf = someRandomIntern.makeForm("shrubbery creation", shrubName);
		bur.signForm(*rrf);
		bur.executeForm(*rrf);
		system(("cat " +  shrubName + "_shrubbery").c_str());
		std::cout <<std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm("don't exist", shrubName);		
	}
	catch (const std::exception & e)
		{	std::cerr << e.what() << std::endl;	  }
	return (0);
}