/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:06:11 by seblin            #+#    #+#             */
/*   Updated: 2024/08/19 09:26:53 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <list>

template <class T, class U>
void printStack( MutantStack<T, U> & mstack )
{
	std::cout << "print count" << std::endl;
	typename MutantStack<T, U>::iterator it = mstack.begin();
	typename MutantStack<T, U>::iterator ite = mstack.end();
	while (it != ite)
		std::cout << *it++ << std::endl;
}
void changeDefCont( void )
{// test with float int
//test constr de copy // asignation
// change list (subject)
	float arr[] = {42, 18, -2, 0, 99}; 
	std::list<float> list(arr, arr + 5);
	std::stack<float, std::list<float> > stack(list);
	MutantStack<float, std::list<float> > mstack;
	printStack<float, std::list<float> >(mstack);
	MutantStack<float, std::list<float> > mstack2(list);
	printStack<float, std::list<float> >(mstack2);
	// MutantStack<float, std::list<float> > mstack(list);
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

	changeDefCont();
	return 0;
}