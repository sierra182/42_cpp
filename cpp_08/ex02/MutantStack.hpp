/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:07:15 by seblin            #+#    #+#             */
/*   Updated: 2024/08/18 12:02:54 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "stack"

template <class T>
class MutantStack : std::stack<T> 
{
	MutantStack( const MutantStack & src );
	MutantStack & operator=( const MutantStack & rhs );
	public:
	MutantStack( void );
	virtual ~MutantStack( void );
};

#include "MutantStack.tpp"
