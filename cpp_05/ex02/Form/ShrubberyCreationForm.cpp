/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:56:06 by seblin            #+#    #+#             */
/*   Updated: 2024/07/31 11:23:40 by seblin           ###   ########.fr       */
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
: Form("Shrubbery", 145, 137)
{
	std::ofstream ofs((target + "_shrubbery").c_str());
	if (!ofs)
		std::cerr << "Error file out" << std::endl;	
	ofs << "   ° \n   ** \n  **** \n ****** \n   ||" << std::endl;
	ofs.close();
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm
	( const ShrubberyCreationForm & src ) : Form(src)
{
	*this = src;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=
	( const ShrubberyCreationForm & rhs )
{
	Form::operator=(rhs);
	
	return (*this);
}