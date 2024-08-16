/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:10:54 by seblin            #+#    #+#             */
/*   Updated: 2024/08/16 22:55:35 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyStyl.hpp"
#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

void printMateria( const MateriaSource & mat )
{
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << mat.getInventory()[i]->getType() << std::endl;
	std::cout << std::endl;
}

int main( void )
{
	std::cout << std::endl;
	std::cout << std::endl;
	MyStyl::addTest("operator = and const copy");
	MyStyl::addActionTest("create src with 4 Cure");
	MateriaSource* src = new MateriaSource();	
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	
	MyStyl::addActionTest("create src 2 with 4 Ice");
	MateriaSource* src2 = new MateriaSource();	
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	
	std::cout << std::endl;
	MyStyl::addActionTest("print src");
	printMateria(*src);
	
	MyStyl::addActionTest("print src 2");
	printMateria(*src2);

	MyStyl::addActionTest("src = src 2");
	*src = *src2;
	
	MyStyl::addActionTest("delete src 2");
	delete src2;
		
	std::cout << std::endl;
	MyStyl::addActionTest("print src");
	printMateria(*src);
	
	MyStyl::addActionTest("src3(src)");
	MateriaSource src3(*src);
	
	MyStyl::addActionTest("delete src");
	delete src;
	std::cout << std::endl;
	MyStyl::addActionTest("print src3");
	printMateria(src3);
	
	return (0);
}

// int	main( void )
// {
	
// 	IMateriaSource* src = new MateriaSource();	
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");		
// 	AMateria* tmp;
// 	// tmp = src->createMateria("mouche");//! other test
// 	tmp = src->createMateria("ice");
// 	//std::cout << "tmp type: " << tmp->getType() << "!" << std::endl;
// 		//! other test	
// 	me->equip(tmp);
// 	// AMateria * save = tmp;//! other test
// 	tmp = src->createMateria("cure");
// 	// std::cout << "tmp type: " << tmp->getType() << "!" << std::endl;	
// 		//! other test
// 	me->equip(tmp);
// 	// me->unequip(0);//! other test
// 	// delete save;//! ! other test
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	std::cout << std::endl;
// 	std::cout << "***************other tests***************" << std::endl;
		
// 	Character* playerOne = new Character("morpheus");	
// 	Character* playerTwo = new Character("trinity");
		
// 	std::cout << std::endl;	
// 	std::cout << "player one: " <<  playerOne->getName()
// 		<< " equip with five Ice" << std::endl << std::endl;
		
// 	playerOne->equip(new Ice());
// 	playerOne->equip(new Ice());
// 	playerOne->equip(new Ice());
// 	playerOne->equip(new Ice());	
// 	Ice iceExcess;
// 	playerOne->equip(&iceExcess);
	
// 	std::cout << playerOne->getName() << std::endl;
// 	for (int i = 0; i < INV + 1; i++)
// 		playerOne->use(i, *playerTwo);
		
// 	std::cout << std::endl;
// 	std::cout << "player two: " << playerTwo->getName()
// 		<< " equip with five Cure" << std::endl << std::endl;
	
// 	playerTwo->equip(new Cure());
// 	playerTwo->equip(new Cure());
// 	playerTwo->equip(new Cure());
// 	playerTwo->equip(new Cure());
// 	Cure cureExcess;
// 	playerTwo->equip(&cureExcess);
	
// 	std::cout << playerTwo->getName() << std::endl;
// 	for (int i = 0; i < INV + 1; i++)
// 		playerTwo->use(i, *playerOne);
// 	std::cout << std::endl;

// 	std::cout << playerOne->getName() << " = " << playerTwo->getName()
// 		<< std::endl;
// 	*playerOne = *playerTwo;
	
// 	std::cout << std::endl;
// 	std::cout << "delete player two: " << playerTwo->getName() << std::endl
// 		<< std::endl;
// 	delete playerTwo;
	
// 	std::cout << "player one: " << "\e[1m" << playerOne->getName() << std::endl;
// 		std::cout << std::endl;
// 	for (int i = 0; i < INV + 1; i++)
// 		playerOne->use(i, *playerOne);
		
// 	std::cout << RST << std::endl;
// 	std::cout << "create player three: copy of player one" << std::endl;
// 	Character playerThree(*playerOne);
// 	std::cout << std::endl;

// 	delete playerOne;
// 	std::cout << "delete player one" << std::endl;
// 	std::cout << std::endl;
	
// 	std::cout << "player three: " << playerThree.getName() << std::endl;
// 	std::cout << std::endl;	
// 	std::cout << "\e[1m" << playerThree.getName() << std::endl;
// 	for (int i = 0; i < INV + 1; i++)
// 		playerThree.use(i, playerThree);
			
// 	std::cout << RST << std::endl;
// 	return 0;
// }