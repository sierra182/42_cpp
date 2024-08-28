/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:50:24 by seblin            #+#    #+#             */
/*   Updated: 2024/08/28 13:27:06 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace myFuncts
{	
	template <typename T>
	void swap( T & a, T & b )
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <typename T>
	T min(const T & a, const T & b )
	{
		return a < b ? a : b;
	}

	template <typename T>
	T max( const T & a, const T & b )
	{
		return a > b ? a : b;
	}
} 
