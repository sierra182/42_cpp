/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:25:23 by svidot            #+#    #+#             */
/*   Updated: 2024/07/23 16:19:08 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main( void )
{
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
	
    
	//  const Animal *b = new Brain(); 
	// (void) b;
	// Brain b;
	// Dog c = b;
	// (void) b;
	

	   Brain b1;
    //Brain b2 = b1; // Appelle le constructeur de copie de Brain, qui appelle le constructeur de copie de Dog
   // b2 = b1;       // Appelle l'opérateur d'affectation de Brain, qui appelle l'opérateur d'affectation de Dog
   
	b1.test();
    // Dog d = b1; // Conversion implicite de Brain à Dog, grâce à using Dog::Dog


// {

//     Brain b1;
//     Brain b2 = b1; // Appelle le constructeur de copie de Brain, qui appelle le constructeur de copie de Dog
//     b2 = b1;       // Appelle l'opérateur d'assignation de Brain, qui appelle l'opérateur d'assignation de Dog

//     Dog d = static_cast<Dog&>(b1); // Conversion explicite de Brain à Dog
// }
//     // std::cout << std::endl;
//     // std::cout << " " << j->getType() << " " << std::endl;
//     // std::cout << " " << i->getType() << " " << std::endl;
//     // std::cout << "\e[5m", i->makeSound(), std::cout << "\e[0m"; 
//     // std::cout << "\e[5m", j->makeSound(), std::cout << "\e[0m";  
//     // meta->makeSound();
//     std::cout << std::endl;
// 	{
//    // delete b;//, delete i, delete meta;
//      Brain b1;         // Appelle Brain::Brain(), pas Dog::Dog()
//     Brain b2 = b1;    // Appelle le constructeur de copie de Brain, qui appelle Dog::Dog(const Dog&)
//     b2 = b1;          // Appelle Brain::operator=, qui appelle Dog::operator=
    
//     // Dog d = b1;   // Erreur : conversion implicite interdite en héritage protégé
//     Dog* d_ptr = &b1; // Correct : conversion implicite autorisée pour les pointeurs/références
// 	(void) d_ptr;
// 	}
    return (0);
}