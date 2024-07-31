/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:39:38 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 21:52:59 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main ( void )
{	
	std::cout << std::endl;
	Intern someRandomIntern;
	AForm* rrf; //? Form *
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout <<std::endl;
	return (0);
}