/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:30:58 by seblin            #+#    #+#             */
/*   Updated: 2024/08/07 13:58:48 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void )
{
	return ;
}	

template <typename T>	
Array<T>::Array( const Array & src )
{
	*this = src;
	return ;
}//

template <typename T>
Array<T> & Array<T>::operator=( const Array & rhs )
{
	//!
	return *this;
}

template <typename T>
Array<T>::~Array( void )
{
	return ;
}