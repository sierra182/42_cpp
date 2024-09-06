/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:07:53 by seblin            #+#    #+#             */
/*   Updated: 2024/09/06 10:57:11 by svidot           ###   ########.fr       */
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
MutantStack<T, U>::MutantStack( const MutantStack<T, U> & src ):
	std::stack<T, U>(src)
{	
	return ;
}

template <class T, class U>
MutantStack<T, U> & MutantStack<T, U>::operator=
	( const MutantStack<T, U> & rhs )
{
	std::stack<T, U>::operator=(rhs);
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

template <class T, class U>
std::ostream & operator<<(std::ostream & oss,
	MutantStack<T, U> & rhs)
{
	typename MutantStack<T, U>::const_iterator it = rhs.begin();
	typename MutantStack<T, U>::const_iterator ite = rhs.end();
	while (it != ite)	
		oss << *it++ << std::endl;		
	
	return (oss);
}