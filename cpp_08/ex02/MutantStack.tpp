/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:07:53 by seblin            #+#    #+#             */
/*   Updated: 2024/08/18 11:23:14 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
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