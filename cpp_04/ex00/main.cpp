/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:25:23 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 16:02:38 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "\e[5m", i->makeSound(), std::cout << "\e[0m"; 
    std::cout << "\e[5m", j->makeSound(), std::cout << "\e[0m";  
    meta->makeSound();
    
    delete j, delete i, delete meta;
    
    {    
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
            
        std::cout << i->getType() << " " << std::endl;           
        std::cout << "\e[5m", i->makeSound(), std::cout << "\e[0m";
        meta->makeSound();
        delete meta, delete i;
    }   
    //! Ajouter les messages const dest et more test!
    return (0);
}