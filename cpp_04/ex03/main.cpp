/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:10:54 by seblin            #+#    #+#             */
/*   Updated: 2024/07/26 17:29:19 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

int	main( void )
{
	// Ice ice;

	// std::cout<< std::endl;
	// Ice* ice2 = new Ice();

	// AMateria * ice3 = new Ice("truc");
	
	// std::cout << "type: " << ice3->getType() << std::endl;

	// AMateria * ice4 = new Cure("machin");
	
	// std::cout << "type: " << ice4->getType() << std::endl;
	// (void) ice3;
	// (void) ice2;

	// Character chara;
	//   AMateria * am = new Ice();

	IMateriaSource* src = new MateriaSource();	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	
	std::cout << std::endl;
	AMateria* tmp;
	std::cout << "bef create ice" << std::endl;

	tmp = src->createMateria("ice");
	
	std::cout << "bef create cure" << std::endl;
	me->equip(tmp);
	AMateria * save = tmp;//!
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(0);//!
	delete save;
	std::cout << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	 
	delete bob;
	delete me;
	delete src;
	return 0;

}