/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:53:38 by seblin            #+#    #+#             */
/*   Updated: 2024/08/15 16:37:42 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstring>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cmath>

Span::Span( void ): _N(0), _set(NULL)
{
	return ;
}

Span::Span( unsigned int N ): _N(N), _set(new std::multiset<int>)
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

const std::multiset<int> & Span::getSet( void ) const
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
	for (std::multiset<int>::const_iterator it = rhs.getSet().begin();
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

unsigned int Span::shortestSpan( void )
{
	std::vector<int> tmp_vect;
	std::multiset<int> tmp_set;
	std::adjacent_difference(this->_set->begin(), this->_set->end(), tmp_vect.begin());
	struct MakeAbs{	int makeAbs(int x) { return std::abs(x); }};
	std::transform(tmp_vect.begin(), tmp_vect.end(), tmp_set.begin(), MakeAbs::makeAbs ); 
	tmp_set.ass
	return (tmp_set.begin());
}

unsigned int Span::longestSpan( void )
{
	return (*this->_set->rbegin() - *this->_set->begin());
}