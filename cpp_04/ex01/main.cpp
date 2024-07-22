/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:25:23 by svidot            #+#    #+#             */
/*   Updated: 2024/07/22 18:50:30 by seblin           ###   ########.fr       */
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
    
    std::cout << std::endl;
    std::cout << " " << j->getType() << " " << std::endl;
    std::cout << " " << i->getType() << " " << std::endl;
    std::cout << "\e[5m", i->makeSound(), std::cout << "\e[0m"; 
    std::cout << "\e[5m", j->makeSound(), std::cout << "\e[0m";  
    meta->makeSound();
    std::cout << std::endl;
    delete j, delete i, delete meta;
    
    std::cout << "   ******************************" << std::endl;
    
    {    
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        
        std::cout << std::endl;  
        std::cout << " " << i->getType() << " " << std::endl;           
        std::cout << "\e[5m", i->makeSound(), std::cout << "\e[0m";
        meta->makeSound();
        std::cout << std::endl;
        delete i, delete meta;
    }
    
	std::cout << "   ///////////////-VAR TEST-///////////////" << std::endl;
    
    {
        const Animal meta = Animal();
        const Animal j = Dog();
        const Animal i = Cat();
               
        std::cout << " " << j.getType() << " " << std::endl;
        std::cout << " " << i.getType() << " " << std::endl;
        std::cout << "\e[5m", i.makeSound(), std::cout << "\e[0m"; 
        std::cout << "\e[5m", j.makeSound(), std::cout << "\e[0m";  
        meta.makeSound();
        std::cout << std::endl;
        
        
        std::cout << "   ******************************" << std::endl;
        
        {    
            const WrongAnimal meta = WrongAnimal();
            const WrongAnimal i = WrongCat();
                         
            std::cout << " " << i.getType() << " " << std::endl;           
            std::cout << "\e[5m", i.makeSound(), std::cout << "\e[0m";
            meta.makeSound();
            std::cout << std::endl;            
        }
    }

  	std::cout << "   ///////////////-PTR TEST-///////////////" << std::endl;
    
    {
        Animal meta = Animal();
        Dog a = Dog();
        Cat b = Cat();
        
        Animal * i = &a;
        Animal * j = &b;
        
        std::cout << std::endl;
        std::cout << " " << j->getType() << " " << std::endl;
        std::cout << " " << i->getType() << " " << std::endl;
        std::cout << "\e[5m", i->makeSound(), std::cout << "\e[0m"; 
        std::cout << "\e[5m", j->makeSound(), std::cout << "\e[0m";  
        meta.makeSound();
        std::cout << std::endl;
        
        
        std::cout << "   ******************************" << std::endl;
        
        {    
            WrongAnimal meta = WrongAnimal();
            WrongAnimal a = WrongCat();
            
            WrongAnimal * i = &a;
                        
            std::cout << " " << i->getType() << " " << std::endl;           
            std::cout << "\e[5m", i->makeSound(), std::cout << "\e[0m";
            meta.makeSound();
            std::cout << std::endl;            
        }
    }

    std::cout << "   ///////////////-REF TEST-///////////////" << std::endl;
    
    {
        Animal meta = Animal();
        Dog a = Dog();
        Cat b = Cat();
        
        Animal & i = a;
        Animal & j = b;
        
        std::cout << std::endl;
        std::cout << " " << j.getType() << " " << std::endl;
        std::cout << " " << i.getType() << " " << std::endl;
        std::cout << "\e[5m", i.makeSound(), std::cout << "\e[0m"; 
        std::cout << "\e[5m", j.makeSound(), std::cout << "\e[0m";  
        meta.makeSound();
        std::cout << std::endl;
        
        
        std::cout << "   ******************************" << std::endl;
        
        {    
            WrongAnimal meta = WrongAnimal();
            WrongAnimal a = WrongCat();
            
            WrongAnimal & i = a;
           
            std::cout << std::endl;  
            std::cout << " " << i.getType() << " " << std::endl;           
            std::cout << "\e[5m", i.makeSound(), std::cout << "\e[0m";
            meta.makeSound();
            std::cout << std::endl;            
        }
    }
    return (0);
}