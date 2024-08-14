/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:51:20 by seblin            #+#    #+#             */
/*   Updated: 2024/08/14 16:27:02 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <set>
#include <stdexcept>
#include <iostream>

class Span
{
	Span( void );
	Span( const Span & src );
	Span & operator=( const Span & rhs );


	
	void shortestSpan( void );
	void longestSpan( void );
	
	const unsigned int _N;
	std::set<int> * _set;
	
	public:
	void addNumber( int nbr );
	template <class Iter>
	void addNumber( Iter start, Iter end );
	
	virtual ~Span( void );
	Span( unsigned int N );


	friend std::ostream & operator<<( std::ostream & oss, const Span & rhs );//!!! frind
};

// std::ostream & operator<<( std::ostream & oss, const Span & rhs );

template <class Iter>
void Span::addNumber( Iter start, Iter end )
{
  //! if end <= start error
	
	if (this->_set && this->_set->size() + std::distance(start, end) <= _N)
		_set->insert(start, end);
	else
		throw std::overflow_error("Max is reached"); //!
}