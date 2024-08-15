/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:53:38 by seblin            #+#    #+#             */
/*   Updated: 2024/08/15 20:10:46 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
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
	return ;
}

Span::~Span( void )
{
	return ;
}

Span::Span( const Span & src ): _set(new std::multiset<int>)
{
	*this = src; 
	return ;
}

Span & Span::operator=( const Span & rhs )
{
	if (this != &rhs)
	{
		if (*this->_set != *rhs._set)
			*this->_set = *rhs._set;
	}		
	return (*this);
}

void Span::addNumber( int nbr )
{
	if (this->_set->size() < this->_N)		
		this->_set->insert(nbr);	
	else
		throw std::overflow_error("Max items is reached!"); 
}

unsigned int Span::shortestSpan( void )
{
	if (this->_set->size() <= 1)
		throw std::underflow_error("Not enought items!");
	std::vector<int> tmp_vect(this->_set->size());
	std::multiset<unsigned int> tmp_set;
	std::adjacent_difference(this->_set->begin(), this->_set->end(),
		tmp_vect.begin());
	struct MakeAbs{	static int makeAbs(int x) { return std::abs(x); }};
	std::transform(tmp_vect.begin(), tmp_vect.end(), tmp_vect.begin(),
		MakeAbs::makeAbs); 
	tmp_set.insert(tmp_vect.begin(), tmp_vect.end());	
	return (*tmp_set.begin());
}

unsigned int Span::longestSpan( void )
{
	if (this->_set->size() <= 1)
		throw std::underflow_error("Not enought items!");
	return (static_cast<unsigned int>(*this->_set->rbegin()
		- *this->_set->begin()));
}

const std::multiset<int> & Span::getSet( void ) const
{
	return (*this->_set);
}

std::ostream & operator<<( std::ostream & oss, const Span & rhs )
{
	for (std::multiset<int>::const_iterator it = rhs.getSet().begin();
		it != rhs.getSet().end(); it++)
		oss << *it << " ";
	oss	<< std::endl;
	return (oss);
}