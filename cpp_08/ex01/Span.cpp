/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:53:38 by seblin            #+#    #+#             */
/*   Updated: 2024/08/14 07:39:16 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstring>

Span::Span( void ): _N(0), _set(NULL)
{
	return ;
}

Span::Span( unsigned int N ): _N(N), _set(new std::set<int>)
{
	
}

Span::~Span( void )
{
	return ;
}

Span::Span( const Span & src ): _N(src._N)
{
	*this = src; 
	return ;
}

Span & Span::operator=( const Span & rhs )
{
	if (this != &rhs)
		*this->_set = *rhs._set; //! verif
	return (*this);
}

void Span::addNumber( int nbr )
{
	if (this->_set && this->_set->size() < _N)
		_set->insert(nbr);
	else
		throw std::overflow_error("Max is reached"); //!
}



void Span::shortestSpan( void )
{
	
}

void Span::longestSpan( void )
{
	
}