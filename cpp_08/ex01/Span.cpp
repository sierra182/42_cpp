/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:53:38 by seblin            #+#    #+#             */
/*   Updated: 2024/08/14 16:29:02 by svidot           ###   ########.fr       */
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


template <class T>
void	print(const T & item)
{
	std::cout << item << std::endl;	
}
#include <algorithm>
std::ostream & operator<<( std::ostream & oss, const Span & rhs )
{
	std::for_each(rhs._set->begin(), rhs._set->end(), print<int>);
	oss << "caca";
	return (oss);
}

#include <iostream>//!
void Span::addNumber( int nbr )
{
	if (this->_set && this->_set->size() < this->_N)
	{
		std::cout << "N" << this->_N << std::endl;	
		_set->insert(nbr);
	}
	else
		throw std::overflow_error("Max is reached"); //!
}

void Span::shortestSpan( void )
{
	
}

void Span::longestSpan( void )
{
	
}