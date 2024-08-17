/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:42:01 by seblin            #+#    #+#             */
/*   Updated: 2024/08/17 17:26:31 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MyStyl.hpp>
#include <Span.hpp>
#include <algorithm>
#include <list>
#include <vector>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <limits>

int getRandom( void )
{
	return rand() - RAND_MAX / 2;
}

void randexec( void )
{
	MyStyl::addAction("create span with list plage");
	Span * sp = new Span(10001);
	std::list<int> lst(10001, 0);
		
	MyStyl::addAction("fill it with random numbers");
	std::generate(lst.begin(), lst.end(), getRandom);
	
	MyStyl::addAction("add list plage to span");
	sp->addNumber(lst.begin(), lst.end());
	
	std::cout << std::endl;		
	MyStyl::addAction("display span");
	std::cout << *sp << std::endl;
	
	MyStyl::addAction("longest span");
	std::cout << sp->longestSpan() << std::endl;
	
	MyStyl::addAction("shortest span");
	std::cout << sp->shortestSpan() << std::endl;
}


void randtest( void )
{
	std::cout << std::endl << std::endl;
	MyStyl::addTest("more 10000");
	try	{			
		std::cout << "ready ?" << std::endl;	
		int t = std::cin.get();
		while (t == '\n' || t == 'y')
		{
			randexec();
			std::cout << "retry ? y / n" << std::endl;			
			if (t != '\n')
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			t = std::cin.get();				
		}							
	}
	catch(const std::exception & e)
		{ MyStyl::addWhat(e.what()); }		
}

void copy( void )
{
	std::cout << std::endl << std::endl;	
	{
		MyStyl::addTest("operator = ");		
		
		try	{
			MyStyl::addAction("create span with N = 4");
			Span sp(4);			
			MyStyl::addAction("fill it");
			{
				int arr[] = {1, 99, -100, -200};
				sp.addNumber(arr, arr + 4);				
			}			
			
			MyStyl::addAction("create span 2 with N = 7");
			Span * sp2 = new Span(7);
			MyStyl::addAction("fill it");
			{				
				int arr[] = {2, 1, 99, -100, -200, 42, 24};
				sp2->addNumber(arr, arr + 7);
			}
			
			std::cout << std::endl;
			MyStyl::addAction("display span");
			std::cout << sp << std::endl;
			MyStyl::addAction("display span 2");
			std::cout << *sp2 << std::endl;			
			MyStyl::addAction("span = span 2");
			sp = *sp2;
			MyStyl::addAction("delete span 2");
			delete sp2;
			std::cout << std::endl;
			MyStyl::addAction("display span");
			std::cout << sp << std::endl;			
		}
		catch(const std::exception & e)
			{ MyStyl::addWhat(e.what()); }
	}
	std::cout << std::endl << std::endl;	
	{
		MyStyl::addTest("const cpy");
				
		try	{			
			MyStyl::addAction("create span 2 with N = 7");
			Span * sp2 = new Span(7);
			MyStyl::addAction("fill it");
			{				
				int arr[] = {2, 1, 99, -100, -200, 42, 24};
				sp2->addNumber(arr, arr + 7);
			}
			
			std::cout << std::endl;		
			MyStyl::addAction("display span 2");
			std::cout << *sp2 << std::endl;
			MyStyl::addAction("create span(span 2)");
			Span sp(*sp2);
			MyStyl::addAction("delete span 2");
			delete sp2;
			std::cout << std::endl;
			MyStyl::addAction("display span");
			std::cout << sp << std::endl;			
		}
		catch(const std::exception & e)
			{ MyStyl::addWhat(e.what()); }
	}
}

void exc( void )
{	
	MyStyl::addTest("exception N max");	
		
	try	{
		MyStyl::addAction("create span with N = 0");		
		Span sp(0);
		MyStyl::addAction("add a number");
		sp.addNumber(1);
	}
	catch(const std::exception & e)
		{ MyStyl::addWhat(e.what()); }
	
	try	{
		MyStyl::addAction("create span with N = 4");

		Span sp(4);
		MyStyl::addAction("add a plage of 5 items");
		int arr[] = {2, 1, 99, -100, -200};
		sp.addNumber(arr, arr + 5);	
	}
	catch(const std::exception & e)
		{ MyStyl::addWhat(e.what()); }	
			
	std::cout << std::endl << std::endl;	
	{
		MyStyl::addTest("exception inversed");	
			
		try	{
			MyStyl::addAction("create span with N = 4");
			Span sp(4);
			MyStyl::addAction("add an inversed plage of 5 items");
			int arr[] = {2, 1, 99, -100, -200};
			sp.addNumber(arr + 5, arr);	
		}
		catch(const std::exception & e)
			{ MyStyl::addWhat(e.what()); }
	}
}

int allTests( void )
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::cout << std::endl << std::endl << std::endl;
	
	exc();
	copy();
	
	std::cout << std::endl << std::endl;	
	{
		MyStyl::addTest("shortest and longest span");
		{		
			MyStyl::addSubTest("zero items");
				
			MyStyl::addAction("create span");
			Span * sp = new Span(7);
			MyStyl::addAction("not fill it");
			std::cout << std::endl;		
			MyStyl::addAction("display span");
			std::cout << *sp << "🐁" << std::endl << std::endl;
			try	{
				MyStyl::addAction("longest span");
				std::cout << sp->longestSpan() << std::endl;
				MyStyl::addAction("shortest span");
				std::cout << sp->shortestSpan() << std::endl;						
			}
			catch(const std::exception & e)
				{ MyStyl::addWhat(e.what()); }
			try	{	
				MyStyl::addAction("shortest span");
				std::cout << sp->shortestSpan() << std::endl;						
			}
			catch(const std::exception & e)
				{ MyStyl::addWhat(e.what()); }
		}
		{		
			MyStyl::addSubTest("one items");
				
			MyStyl::addAction("create span");
			Span * sp = new Span(7);
			MyStyl::addAction("fill it");
			sp->addNumber(-42);
			std::cout << std::endl;		
			MyStyl::addAction("display span");
			std::cout << *sp << std::endl;
			try	{
				MyStyl::addAction("longest span");
				std::cout << sp->longestSpan() << std::endl;
				MyStyl::addAction("shortest span");
				std::cout << sp->shortestSpan() << std::endl;						
			}
			catch(const std::exception & e)
				{ MyStyl::addWhat(e.what()); }
			try	{	
				MyStyl::addAction("shortest span");
				std::cout << sp->shortestSpan() << std::endl;						
			}
			catch(const std::exception & e)
				{ MyStyl::addWhat(e.what()); }
		}
		
		try	{
			MyStyl::addSubTest("normal way 1");			
			MyStyl::addAction("create span with plage");
			Span * sp = new Span(7);
			MyStyl::addAction("fill it");
			{				
				int arr[] = {2, 1, 99, -100, -200, 42, 24};
				sp->addNumber(arr, arr + 7);
			}
			std::cout << std::endl;		
			MyStyl::addAction("display span");
			std::cout << *sp << std::endl;
			MyStyl::addAction("longest span");
			std::cout << sp->longestSpan() << std::endl;
			MyStyl::addAction("shortest span");
			std::cout << sp->shortestSpan() << std::endl;
					
		}
		catch(const std::exception & e)
			{ MyStyl::addWhat(e.what()); }
			
		std::cout << std::endl << std::endl;
			try	{
			MyStyl::addSubTest("normal way 2");			
			MyStyl::addAction("create span with plage");
			Span * sp = new Span(7);
			MyStyl::addAction("fill it");
			{				
				int arr[] = {42, -3, 0, -100, 11, 520, 7, 0, 11};
				sp->addNumber(arr, arr + 7);
			}
			std::cout << std::endl;		
			MyStyl::addAction("display span");
			std::cout << *sp << std::endl;
			MyStyl::addAction("longest span");
			std::cout << sp->longestSpan() << std::endl;
			MyStyl::addAction("shortest span");
			std::cout << sp->shortestSpan() << std::endl;
					
		}
		catch(const std::exception & e)
			{ MyStyl::addWhat(e.what()); }
		
		randtest();
	}	
	return (0);
}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	allTests();
	return 0;
}
