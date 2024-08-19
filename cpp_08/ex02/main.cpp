/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:06:11 by seblin            #+#    #+#             */
/*   Updated: 2024/08/19 10:32:42 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include "MyStyl.hpp"

template <class T, class U>
void printStack( MutantStack<T, U> & mstack )
{	
	typename MutantStack<T, U>::iterator it = mstack.begin();
	typename MutantStack<T, U>::iterator ite = mstack.end();
	while (it != ite)
		std::cout << *it++ << std::endl;
}
void changeDefCont( void )
{
	//overload <<
	
//test constr de copy // asignation

	MyStyl::addTest("MutantStack with List as default Container");
	MyStyl::addSubTest("MutantStack with default constructor");
	
	
	MyStyl::addAction("MutantStack<float, std::list<float> > mstack");
	MutantStack<float, std::list<float> > mstack;
	MyStyl::addAction("push 42");
	mstack.push(42);
	std::cout << std::endl;
	MyStyl::addAction("print mstack");
	std::cout << mstack << std::endl;
	MyStyl::addSubTest("MutantStack with container constructor");
	MyStyl::addAction("create list : 42, 18, -2, 0, 99");
	float arr[] = {42, 18, -2, 0, 99}; 
	std::list<float> list(arr, arr + 5);
	MyStyl::addAction("MutantStack<float, std::list<float> > mstack2(list)");
	// printStack<float, std::list<float> >(mstack);
	MutantStack<float, std::list<float> > mstack2(list);
	std::cout << std::endl;
	MyStyl::addAction("print mstack 2");
	std::cout << mstack2 << std::endl;
	// printStack<float, std::list<float> >(mstack2);	
}

void changeWithList( void )
{
	MyStyl::addTest("changing MutantStack with List");
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int, std::list<int> > s(list);
}

int main()
{	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	changeWithList();
	changeDefCont();
	return 0;
}