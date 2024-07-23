/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:25:23 by svidot            #+#    #+#             */
/*   Updated: 2024/07/23 23:49:05 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

int main( void )
{
	size_t const len = 10;
	Animal ** animal = new Animal*[10];
	
	for (size_t i = 0; i < len * 0.5; i++)
		animal[i] = new Dog();
		
	for (size_t i = len * 0.5; i < len; i++)
		animal[i] = new Cat();

	for (size_t i = 0; i < len; i++)
		animal[i]->makeSound();

	for (size_t i = 0; i < len; i++)
		delete animal[i];
		
	delete[] animal;

	Dog dog = Dog();
	std::cout << ' ' << dog.getType() << std::endl;
	dog.makeSound();
	
	std::cout << dog.getBrain().ideas[0] << std::endl;
	std::cout << dog.getBrain().ideas[1] << std::endl;
	std::cout << dog.getBrain().ideas[2] << std::endl;

	Dog dog2 = dog; //!verif si rhs bien copié
	std::cout << dog2.getBrain().ideas[0] << std::endl;
	std::cout << dog2.getBrain().ideas[1] << std::endl;
	std::cout << dog2.getBrain().ideas[2] << std::endl;
	
	dog.getBrain().ideas[0] = "i 've forgotten";
	dog.getBrain().ideas[1] = "i 've forgotten";
	dog.getBrain().ideas[2] = "i 've forgotten";
	
	std::cout << dog.getBrain().ideas[0] << std::endl;
	std::cout << dog.getBrain().ideas[1] << std::endl;
	std::cout << dog.getBrain().ideas[2] << std::endl;
	
	Dog dog3;
	dog3 = dog;
	
	std::cout << dog3.getBrain().ideas[0] << std::endl;
	std::cout << dog3.getBrain().ideas[1] << std::endl;
	std::cout << dog3.getBrain().ideas[2] << std::endl;
		
	// (void) animal;
	// Dog mal = Dog();
	// Animal * malref = &mal;
	// Animal no = *malref; 
	// no.makeSound();
    return (0);
}