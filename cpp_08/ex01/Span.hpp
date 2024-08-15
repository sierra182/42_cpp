/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:51:20 by seblin            #+#    #+#             */
/*   Updated: 2024/08/15 16:13:11 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <set>
#include <stdexcept>
#include <iostream>
#include <set>

class Span
{
	Span( void );
	Span( const Span & src );
	Span & operator=( const Span & rhs );
	
	
	const unsigned int _N;
	std::multiset<int> * _set;
	
	public:
	void addNumber( int nbr );
	unsigned int longestSpan( void );
	unsigned int shortestSpan( void );
	template <class Iter>
	void addNumber( Iter start, Iter end );
	const std::multiset<int> & getSet( void ) const;	
	virtual ~Span( void );
	Span( unsigned int N );	
};

std::ostream & operator<<( std::ostream & oss, const Span & rhs );

template <class Iter>
void Span::addNumber( Iter start, Iter end )
{
  //! if end <= start error
	
	if (this->_set && this->_set->size() + static_cast<size_t>(std::distance(start, end)) <= _N)
		_set->insert(start, end);
	else
		throw std::overflow_error("Max is reached"); //!
}