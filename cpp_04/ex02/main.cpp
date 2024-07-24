/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:25:23 by svidot            #+#    #+#             */
/*   Updated: 2024/07/24 09:31:38 by seblin           ###   ########.fr       */
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
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;
		delete j;//should not create a leak
		delete i;
	}
	
	std::cout << "**********start tests**********" << std::endl;
	size_t const len = 10;
	Animal ** animal = new Animal*[10];
	
	for (size_t i = 0; i < len * 0.5; i++)
		animal[i] = new Dog();
		
	for (size_t i = len * 0.5; i < len; i++)
		animal[i] = new Cat();
	
	std::cout << std::endl;
	
	for (size_t i = 0; i < len; i++)
		animal[i]->makeSound();

	std::cout << std::endl;
	
	for (size_t i = 0; i < len; i++)
		delete animal[i];

	delete[] animal;	
	{
		std::cout << "**********other tests**********" << std::endl;
				
		Dog dog;
		
		std::cout << std::endl;
		dog.makeSound();
		std::cout << "\e[1m" << ' ' << dog.getType() << RST << std::endl;
		std::cout << "\e[1m" <<  dog.getBrain().ideas[0] << RST << std::endl;
		std::cout << "\e[1m" << dog.getBrain().ideas[1] << RST << std::endl;
		std::cout << "\e[1m" << dog.getBrain().ideas[2] << RST << std::endl;
		
		dog.setType("notype");
		dog.getBrain().ideas[0] = "i 've forgotten";
		dog.getBrain().ideas[1] = "i 've forgotten";
		dog.getBrain().ideas[2] = "i 've forgotten";
		
		std::cout << std::endl;
		std::cout << " dog modification:" << std::endl;
		std::cout << std::endl;
		dog.makeSound();
		std::cout << ' ' << dog.getType() << std::endl;	
		std::cout << "\e[1m" <<  dog.getBrain().ideas[0] << RST << std::endl;
		std::cout << "\e[1m" << dog.getBrain().ideas[1] << RST << std::endl;
		std::cout << "\e[1m" << dog.getBrain().ideas[2] << RST << std::endl;
		
		std::cout << std::endl;
		std::cout << " create new dog:" << std::endl;
		Dog dog2;
		std::cout << std::endl;
		dog2.makeSound();
		std::cout << ' ' << dog2.getType() << std::endl;	
		std::cout << "\e[1m" <<  dog2.getBrain().ideas[0] << RST << std::endl;
		std::cout << "\e[1m" << dog2.getBrain().ideas[1] << RST << std::endl;
		std::cout << "\e[1m" << dog2.getBrain().ideas[2] << RST << std::endl;
		
		std::cout << std::endl;
		std::cout << " copy of dog to newdog:" << std::endl;
		dog2 = dog;
		std::cout << std::endl;
		dog2.makeSound();
		std::cout << ' ' << dog2.getType() << std::endl;	
		std::cout << "\e[1m" <<  dog2.getBrain().ideas[0] << RST << std::endl;
		std::cout << "\e[1m" << dog2.getBrain().ideas[1] << RST << std::endl;
		std::cout << "\e[1m" << dog2.getBrain().ideas[2] << RST << std::endl;
		
		std::cout << std::endl;
		
		{
			std::cout << "**********tests copy cat to dog**********" << std::endl;
			
			Dog dog;
			std::cout << std::endl;			
			dog.makeSound();
			std::cout << ' ' << dog.getType() << std::endl;	
			std::cout << "\e[1m" <<  dog.getBrain().ideas[0] << RST << std::endl;
			std::cout << "\e[1m" << dog.getBrain().ideas[1] << RST << std::endl;
			std::cout << "\e[1m" << dog.getBrain().ideas[2] << RST << std::endl;

			Cat cat;
			std::cout << std::endl;
			cat.makeSound();
			std::cout << ' ' << cat.getType() << std::endl;	
			std::cout << "\e[1m" <<  cat.getBrain().ideas[0] << RST << std::endl;
			std::cout << "\e[1m" << cat.getBrain().ideas[1] << RST << std::endl;
			std::cout << "\e[1m" << cat.getBrain().ideas[2] << RST << std::endl;
			
			std::cout << std::endl;
			std::cout << " copy of animal member cat to dog:" << std::endl;
			std::cout << std::endl;

			Animal & cat_ref = cat;
			Animal & dog_ref = dog;			
			
			dog_ref = cat_ref;
			dog_ref.makeSound();			
			Dog & dog2 = dynamic_cast<Dog &> (dog_ref);
			std::cout << "\e[5m" << ' ' << dog2.getType() << RST << std::endl;	
			std::cout << "\e[1m" <<  dog2.getBrain().ideas[0] << RST << std::endl;
			std::cout << "\e[1m" << dog2.getBrain().ideas[1] << RST << std::endl;
			std::cout << "\e[1m" << dog2.getBrain().ideas[2] << RST << std::endl;
			std::cout << std::endl;
		}
	}		
    return (0);
}