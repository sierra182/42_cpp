/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:07:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/19 09:27:25 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>

template <class T, class U>
MutantStack<T, U>::MutantStack( void )
{

	return ;
}

template <class T, class U>
MutantStack<T, U>::MutantStack( const U & cont ) : std::stack<T, U>(cont)
{
	return ;
}

template <class T, class U>
MutantStack<T, U>::MutantStack( const MutantStack & src ) //! to test
{
	*this = src;
	return ;
}

template <class T, class U>
MutantStack<T, U> & MutantStack<T, U>::operator=( const MutantStack & rhs ) //! to complete
{
	return *this; 
}

template <class T, class U>
MutantStack<T, U>::~MutantStack( void )
{
	return ;
}

template <class T, class U>
typename MutantStack<T, U>::iterator MutantStack<T, U>::begin( void )
{
	return this->c.begin();
}

template <class T, class U>
typename MutantStack<T, U>::iterator MutantStack<T, U>::end( void )
{
	return this->c.end();
}