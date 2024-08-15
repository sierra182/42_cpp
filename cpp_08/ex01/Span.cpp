/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:53:38 by seblin            #+#    #+#             */
/*   Updated: 2024/08/15 14:49:20 by svidot           ###   ########.fr       */
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

const std::set<int> & Span::getSet( void ) const
{
	return (*this->_set);
}

Span & Span::operator=( const Span & rhs )
{
	if (this != &rhs)
		*this->_set = *rhs._set; //! verif
	return (*this);
}

std::ostream & operator<<( std::ostream & oss, const Span & rhs )
{
	for (std::set<int>::const_iterator it = rhs.getSet().begin();
		it != rhs.getSet().end(); it++)
		oss << *it << " ";
	oss	<< std::endl;
	return (oss);
}

void Span::addNumber( int nbr )
{
	if (this->_set && this->_set->size() < this->_N)
	{
		// std::cout << "N" << this->_N << std::endl;	
		this->_set->insert(nbr);
	}
	else
		throw std::overflow_error("Max is reached"); //!
}

std::ptrdiff_t Span::shortestSpan( void )
{
	return 0;
}

int Span::longestSpan( void )
{
	return (*this->_set->rbegin() - *this->_set->begin());

	// this->_set
}