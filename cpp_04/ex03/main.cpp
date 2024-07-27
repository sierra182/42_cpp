/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:10:54 by seblin            #+#    #+#             */
/*   Updated: 2024/07/27 10:40:55 by svidot           ###   ########.fr       */
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
	// AMateria * save = tmp;//! other test
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// me->unequip(0);//! other test
	// delete save;//! ! other test
	std::cout << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
		 
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;
	std::cout << "***************other tests***************" << std::endl;
	std::cout << std::endl;
	
	Character playerOne("morpheus");	
	Character playerTwo("trinity");
		
	std::cout << std::endl;
	
	std::cout << playerOne.getName() <<  " equip with five Ice" << std::endl;
	
	playerOne.equip(new Ice());
	playerOne.equip(new Ice());
	playerOne.equip(new Ice());
	playerOne.equip(new Ice());
	
	Ice iceExcess;
	playerOne.equip(&iceExcess);
	
	std::cout << playerOne.getName() << std::endl;
	for (int i = 0; i < INV + 1; i++)
		playerOne.use(i, playerTwo);
	
	std::cout << playerTwo.getName() << " equip with five Cure" << std::endl;
	
	playerTwo.equip(new Cure());
	playerTwo.equip(new Cure());
	playerTwo.equip(new Cure());
	playerTwo.equip(new Cure());
	Cure cureExcess;
	playerTwo.equip(&cureExcess);
	
	std::cout << playerTwo.getName() << std::endl;
	for (int i = 0; i < INV + 1; i++)
		playerTwo.use(i, playerOne);
	std::cout << std::endl;

	std::cout << playerOne.getName() << " assign = with "
		<< playerTwo.getName() << std::endl;
	playerOne = playerTwo;
	
	std::cout << playerOne.getName() << std::endl;
	for (int i = 0; i < INV + 1; i++)
		playerOne.use(i, playerTwo);
		
	// Character playerThree("hy");
	std::cout << "unequip" << std::endl;
	Character playerThree(playerOne);
	
	for (int i = 0; i < INV + 1; i++)
		playerOne.unequip(i);
	for (int i = 0; i < INV + 1; i++)
		playerOne.use(i, playerThree);
	std::cout << "after use" << std::endl;	
	std::cout << playerThree.getName() << std::endl;
	for (int i = 0; i < INV + 1; i++)
		playerThree.use(i, playerThree);
	// delete playerOne;
	// delete playerTwo;
	
	return 0;

}