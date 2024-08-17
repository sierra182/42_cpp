/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:10:54 by seblin            #+#    #+#             */
/*   Updated: 2024/08/17 09:44:59 by svidot           ###   ########.fr       */
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

void materiaSoureCopyTest( void )
{
	std::cout << std::endl;
	std::cout << std::endl;
	MyStyl::addTest("MateriaSource");
	
	MyStyl::addActionTest("create src with 5 Cure");
	MateriaSource* src = new MateriaSource();
	for (int i = 0; i < INV; i++)
		src->learnMateria(new Cure());
	Cure cure;	
	src->learnMateria(&cure);
	MyStyl::addActionTest("create src 2 with 5 Ice");
	MateriaSource* src2 = new MateriaSource();	
	for (int i = 0; i < INV; i++)
		src2->learnMateria(new Ice());
	Ice ice;	
	src->learnMateria(&ice);

	MyStyl::addActionTest("print src");
	printMateria(*src);
	
	MyStyl::addActionTest("print src 2");
	printMateria(*src2);

	MyStyl::addActionTest("src = src 2");
	*src = *src2;
	
	MyStyl::addActionTest("delete src 2");
	delete src2;
		
	MyStyl::addActionTest("print src");
	printMateria(*src);
	
	MyStyl::addActionTest("src3(src)");
	MateriaSource src3(*src);
	
	MyStyl::addActionTest("delete src");
	delete src;
	std::cout << std::endl;
	MyStyl::addActionTest("print src3");
	printMateria(src3);
	
	MyStyl::addActionTest("create adamantium");
	src3.createMateria("adamantium");
	std::cout <<std::endl;
}

void characterCopyTest( void )
{
	MyStyl::addTest("Character");
	
	MyStyl::addActionTest("create player one : Morpheus");
	MyStyl::addActionTest("create player two : Trinity");
	Character* playerOne = new Character("morpheus");	
	Character* playerTwo = new Character("trinity");
		
	std::cout << std::endl;	
	std::cout << "player one: " << "\e[1m" << playerOne->getName()
		<< " equip with five Ice" << std::endl << std::endl;
	
	for (int i = 0; i < INV; i++)	
		playerOne->equip(new Ice());	
	Ice iceExcess;
	playerOne->equip(&iceExcess);
	
	std::cout << playerOne->getName() << std::endl;
	for (int i = 0; i < INV + 1; i++)
		playerOne->use(i, *playerTwo);

	std::cout << "player two: " << "\e[1m" << playerTwo->getName()
		<< " equip with five Cure" << std::endl << std::endl;
	
	for (int i = 0; i < INV; i++)	
		playerTwo->equip(new Cure());
	Cure cureExcess;
	playerTwo->equip(&cureExcess);
	
	std::cout << playerTwo->getName() << std::endl;
	for (int i = 0; i < INV + 1; i++)
		playerTwo->use(i, *playerOne);	

	MyStyl::addActionTest(playerOne->getName() + " = " + playerTwo->getName());
	*playerOne = *playerTwo;
	
	std::cout << std::endl;

	MyStyl::addActionTest("delete player two: " + playerTwo->getName());

	delete playerTwo;
	std::cout << std::endl;
	std::cout << "player one: " << "\e[1m" << playerOne->getName()
		<< std::endl;
	std::cout << "\e[0m";
	std::cout << std::endl;
	for (int i = 0; i < INV; i++)
		playerOne->use(i, *playerOne);

	std::cout << std::endl;		
	MyStyl::addActionTest("create player three: playerThree(playerOne)");
	Character playerThree(*playerOne);
	std::cout << std::endl;

	delete playerOne;
	MyStyl::addActionTest("delete player one");
	std::cout << std::endl;
	
	std::cout << "player three: " << "\e[1m" << playerThree.getName()
		<< std::endl;
	std::cout << std::endl;	
	std::cout << "\e[1m" << playerThree.getName() << std::endl;
	std::cout << "\e[0m";
	for (int i = 0; i < INV; i++)
		playerThree.use(i, playerThree);
	
	std::cout << std::endl;	
	MyStyl::addActionTest("unequip unknown index");
	playerThree.unequip(42);	
}

int	main( void )
{	
	IMateriaSource* src = new MateriaSource();	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");		
	AMateria* tmp;
	// tmp = src->createMateria("mouche");//! other test
	tmp = src->createMateria("ice");
	// std::cout << "tmp type: " << tmp->getType() << "!" << std::endl;
		//! other test	
	me->equip(tmp);
	// AMateria * save = tmp;//! other test
	tmp = src->createMateria("cure");
	// std::cout << "tmp type: " << tmp->getType() << "!" << std::endl;	
		//! other test
	me->equip(tmp);
	// me->unequip(0);//! other test
	// delete save;//! ! other test
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;

	materiaSoureCopyTest();
	characterCopyTest();
	return 0;
}