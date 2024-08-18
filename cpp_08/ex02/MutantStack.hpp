/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:07:15 by seblin            #+#    #+#             */
/*   Updated: 2024/08/18 11:19:07 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "stack"

template <class T>
class MutantStack : std::stack 
{
	MutantStack( void );
	MutantStack( const MutantStack & src );
	MutantStack & operator=( const MutantStack & rhs );
	virtual ~MutantStack( void );
};

#include "MutantStack.tpp"
