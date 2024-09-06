/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:07:15 by seblin            #+#    #+#             */
/*   Updated: 2024/09/06 10:56:59 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "stack"
#include <ostream>

template <class T, class U = std::deque<T> >
class MutantStack : public std::stack<T, U> 
{
	public:
		MutantStack( void );
		MutantStack( const U & cont );
		MutantStack( const MutantStack<T, U> & src );
		MutantStack & operator=( const MutantStack<T, U> & rhs );
		virtual ~MutantStack( void );

		typedef typename U::iterator iterator;
		typedef typename U::const_iterator const_iterator;
		
		typename MutantStack<T, U>::iterator begin( void );
		typename MutantStack<T, U>::iterator end( void );
};

template <class T, class U>
std::ostream & operator<<(std::ostream & oss,
	MutantStack<T, U> & rhs);

#include "MutantStack.tpp"
