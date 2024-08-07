/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:55:55 by seblin            #+#    #+#             */
/*   Updated: 2024/08/07 12:19:10 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <typeinfo>

template <typename T>
void iter( T * array, const size_t lenght, void (*f)(T arg) )
{
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
	std::cout << std::endl << " *********" << std::endl;
}

template <typename T>
void myfunct( T arg )
{
	std::cout << "\e[1;35m you're in a generic template \e[0m" <<std::endl;
	std::cout << "\e[1;31m " << arg  << "\e[0m" << std::endl;
	std::cout << " my info type is: " << typeid(arg).name() << std::endl;
	std::cout <<  " my weight is : " << sizeof(arg) << " ko" 
		<<  std::endl;
	std::cout << std::endl;
}

template <>
void myfunct<std::string>( std::string arg )
{
	std::cout << "\e[1;35m you're in a specialized template \e[0m" <<std::endl;
	std::cout << "\e[1;31m " << arg  << "\e[0m" << std::endl;
	std::cout << " my info type is: " << typeid(arg).name() << std::endl;
	std::cout <<  "\e[5m my lenght is : " << arg.length() << "\e[0m"
		<< std::endl;
	std::cout << std::endl;
}
