/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:06:11 by seblin            #+#    #+#             */
/*   Updated: 2024/09/01 18:02:49 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include "MyStyl.hpp"

void copy( void )
{	
	MyStyl::addTest("deep copy");
	
	{
		MyStyl::addSubTest("operator =");
	
		MyStyl::addAction("create empty mstack");
		MutantStack<int, std::list<int> > mstack;
		
		std::cout << std::endl;
		MyStyl::addAction("print mstack");
		std::cout << mstack << "🐁" << std::endl;
		std::cout << std::endl;	
		{	
			MyStyl::addAction("create new mstack 2, fill with 42, 18, -2, 0, 99");
			int arr[] = {42, 18, -2, 0, 99}; 
			std::list<int> list(arr, arr + 5);
			MutantStack<int, std::list<int> > mstack2(list);
			
			std::cout << std::endl;
			MyStyl::addAction("print mstack 2");
			std::cout << mstack2 << std::endl;
			
			MyStyl::addAction("mstack = mstack2");
			mstack = mstack2;
			MyStyl::addAction("delete mstack2");
		}		
		std::cout << std::endl;
		MyStyl::addAction("print mstack");
		std::cout << mstack << std::endl;
	}
	{
		MyStyl::addSubTest("copy constr");
			
		std::cout << std::endl;	
		{	
			MyStyl::addAction("create new mstack, fill with 42, 18, -2, 0, 99");
			int arr[] = {42, 18, -2, 0, 99}; 
			std::deque<int> deq(arr, arr + 5);
			MutantStack<int> * mstack = new MutantStack<int>(deq);
			
			std::cout << std::endl;
			MyStyl::addAction("print mstack");
			std::cout << *mstack << std::endl;
			
			MyStyl::addAction("MutantStack<int> mstack2(mstack)");
			MutantStack<int> mstack2(*mstack);			
			MyStyl::addAction("delete mstack");
			delete mstack;
			std::cout << std::endl;
			MyStyl::addAction("print mstack 2");
			std::cout << mstack2 << std::endl;
		}
		{
			// test const;
			int arr[] = {42, 18, -2, 0, 99}; 
			std::deque<int> deq(arr, arr + 5);
			const MutantStack<int> * mstack = new MutantStack<int>(deq);
			// mstack->push(42);
		}	
	}
}

void changeDefCont( void )
{	
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
	float arr[] = {42.1f, 18.2f, -2.5f, 0, 99.6f}; 
	std::list<float> list(arr, arr + 5);
	MyStyl::addAction("MutantStack<float, std::list<float> > mstack2(list)");
	MutantStack<float, std::list<float> > mstack2(list);

	std::cout << std::endl;
	MyStyl::addAction("print mstack 2");
	std::cout << mstack2 << std::endl;
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
	copy();
	return 0;
}