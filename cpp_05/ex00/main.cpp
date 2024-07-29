/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:39:38 by seblin            #+#    #+#             */
/*   Updated: 2024/07/29 11:55:07 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
// #include <stdexcept>
#include <iostream>

int main (void )
{
	try	
	{
		Bureaucrat bur("jean", 42);
		Bureaucrat bur2("jeanne", -42);


			
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{		
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "gen " << e.what() << std::endl;
	}
	return (0);
}