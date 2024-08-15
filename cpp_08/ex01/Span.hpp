/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:51:20 by seblin            #+#    #+#             */
/*   Updated: 2024/08/15 20:11:19 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <set>
#include <stdexcept>
#include <iostream>

class Span
{
	Span( void );	
	
	unsigned int _N;
	std::multiset<int> * const _set;
	
	public:
	
		Span( unsigned int N );	
		Span( const Span & src );
		Span & operator=( const Span & rhs );
		virtual ~Span( void );
		
		void addNumber( int nbr );
		template <class Iter>
		void addNumber( Iter start, Iter end );
		unsigned int longestSpan( void );
		unsigned int shortestSpan( void );
		
		const std::multiset<int> & getSet( void ) const;	
};

template <class Iter>
void Span::addNumber( Iter start, Iter end )
{
	if (std::distance(start, end) < 0)
		throw std::invalid_argument("Invalid range: end precedes start!");
	if (this->_set->size() + static_cast<size_t>(std::distance(start, end))
		<= _N)
		_set->insert(start, end);
	else
		throw std::overflow_error("Max items is reached!");
}

std::ostream & operator<<( std::ostream & oss, const Span & rhs );