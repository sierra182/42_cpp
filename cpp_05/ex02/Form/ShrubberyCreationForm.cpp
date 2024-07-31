/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:56:06 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 14:08:29 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void )
{
	return ;
}
	
ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target )
: AForm("Shrubbery", 145, 137)
{	
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm
	( const ShrubberyCreationForm & src ) : AForm(src)
{
	*this = src;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=
	( const ShrubberyCreationForm & rhs )
{
	AForm::operator=(rhs);
	
	return (*this);
}

void ShrubberyCreationForm::action( void ) const
{
	std::ofstream ofs((this->_target + "_shrubbery").c_str());
	if (!ofs)
		std::cerr << "Error file out" << std::endl;	
	ofs << "   ° \n   ** \n  **** \n ****** \n   ||" << std::endl;
	ofs.close();
	
	return ;
}