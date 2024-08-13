/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:53:38 by seblin            #+#    #+#             */
/*   Updated: 2024/08/13 18:16:35 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstring>

Span::Span( void ): _set(NULL)
{
	return ;
}

Span::Span( unsigned int N ): _set(new std::set<int>)
{
	
}

Span::~Span( void )
{
	return ;
}

Span::Span( const Span & src )
{
	return ;
}

Span & Span::operator=( const Span & rhs )
{
	return ;
}

void Span::addNumber( void )
{
	
}

void Span::shortestSpan( void )
{
	
}

void Span::longestSpan( void )
{
	
}