/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:55:55 by seblin            #+#    #+#             */
/*   Updated: 2024/08/06 17:54:15 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T, typename U>
void iter(T * array, const U lenght, void (*f)(T arg))
{
	for (U i = 0; i < lenght; i++)
		f(array[i]);
}

template <typename T>
void myfunct(T arg)
{
	std::cout << arg << std::endl;
}