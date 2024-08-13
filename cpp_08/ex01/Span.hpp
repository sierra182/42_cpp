/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:51:20 by seblin            #+#    #+#             */
/*   Updated: 2024/08/13 18:00:21 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <set>

class Span
{
	Span( void );
	virtual ~Span( void );
	Span( const Span & src );
	Span & operator=( const Span & rhs );

	void addNumber( void );
	void shortestSpan( void );
	void longestSpan( void );

	std::set<int> * _set;
	
	public:
		Span( unsigned int N );
};