/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:07:15 by seblin            #+#    #+#             */
/*   Updated: 2024/08/19 07:41:01 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "stack"

template <class T>
class MutantStack : public std::stack<T> 
{
	MutantStack( const MutantStack & src );
	MutantStack & operator=( const MutantStack & rhs );
	public:
	MutantStack( void );
	virtual ~MutantStack( void );

	typedef typename std::deque<T>::iterator iterator;
	// template <class T>
	typename MutantStack<T>::iterator begin( void );
	typename MutantStack<T>::iterator end( void );
	// std::deque<T>::iterator & operator++( const std::deque<T>::iterator & rhs )
	// ;
};

// template <class T>
// std::deque<T>::iterator & MutantStack<T>::operator++( const std::deque<T>::iterator & rhs )
// {
	
// }

#include "MutantStack.tpp"
