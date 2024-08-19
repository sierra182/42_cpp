/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:07:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/19 07:40:27 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>

template <class T>
MutantStack<T>::MutantStack( void )
{

	return ;
}

template <class T>
MutantStack<T>::MutantStack( const MutantStack & src ) //! to test
{
	*this = src;
	return ;
}

template <class T>
MutantStack<T> & MutantStack<T>::operator=( const MutantStack & rhs ) //! to complete
{
	return *this; 
}

template <class T>
MutantStack<T>::~MutantStack( void )
{
	return ;
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::begin( void )
{
	return this->c.begin();
}

template <class T>
typename MutantStack<T>::iterator MutantStack<T>::end( void )
{
	return this->c.end();
}