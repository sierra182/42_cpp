/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:30:58 by seblin            #+#    #+#             */
/*   Updated: 2024/08/07 15:50:22 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void )
{
	//create an empty array
	return ;
}	

template <typename T>	
Array<T>::Array( const Array & src )
{
	/*In both cases, modifying either the
	original array or its copy after copying musn’t affect the other array.*/
	//!
	*this = src;
	return ;
}

template <typename T>
Array<T> & Array<T>::operator=( const Array & rhs )
{
	/*In both cases, modifying either the
	original array or its copy after copying musn’t affect the other array.*/
	//!
	return *this;
}

template <typename T>
Array<T>::~Array( void )
{
	return ;
}

template <typename T>
Array<T>::Array( const unsigned int n )//? const 
{
	/*Creates an array of n elements
	initialized by default.
	Tip: Try to compile int * a = new int(); then display *a*/
	
}