/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:50:24 by seblin            #+#    #+#             */
/*   Updated: 2024/08/06 17:05:11 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap( T & a, T & b )
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min( T & a, T & b )
{
	return a < b ? a : b;
}

template <typename T>
T max( T & a, T & b )
{
	return a > b ? a : b;
}

