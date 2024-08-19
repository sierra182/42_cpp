/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:07:15 by seblin            #+#    #+#             */
/*   Updated: 2024/08/19 10:24:09 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "stack"
#include <ostream>

template <class T, class U = std::deque<T> >
class MutantStack : public std::stack<T, U> 
{
	MutantStack( const MutantStack & src );
	MutantStack & operator=( const MutantStack & rhs );
	public:
	MutantStack( void );
	MutantStack( const U & cont);
	virtual ~MutantStack( void );

	// typedef typename std::deque<T>::iterator iterator;
	typedef typename U::iterator iterator;
	typedef typename U::const_iterator const_iterator;
	// template <class T>
	typename MutantStack<T, U>::iterator begin( void );
	typename MutantStack<T, U>::iterator end( void );
	// std::deque<T>::iterator & operator++( const std::deque<T>::iterator & rhs )
	// ;
};

template <class T, class U>
std::ostream & operator<<(std::ostream & oss,
	MutantStack<T, U> & rhs);

// template <class T>
// std::deque<T>::iterator & MutantStack<T>::operator++( const std::deque<T>::iterator & rhs )
// {
	
// }

#include "MutantStack.tpp"
