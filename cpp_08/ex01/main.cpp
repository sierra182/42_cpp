/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:42:01 by seblin            #+#    #+#             */
/*   Updated: 2024/08/17 15:44:15 by svidot           ###   ########.fr       */
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
// template <class T>
// void	print(const T & item)
// {
// 	std::cout << item << std::endl;	
// }

int getRandom()
{
	return rand() - RAND_MAX / 2;
}

void myrand()
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

int main( void )
{
	std::cout << std::endl << std::endl << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
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
	}
	
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
std::cout << "\033[s";
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
		std::cout << std::endl << std::endl;
		MyStyl::addTest("more 10000");
		try	{
			// std::cout << "\033[s";
			// std::cout << "bala" << std::endl;
			std::cout << "ready ? :y" << std::endl;
			 
			while (std::cin.get() == 'y')
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				myrand();
				std::cout << "retry ? y / n" << std::endl;
				// std::cin.ignore();
				// if (!std::cin.eof())
				// 	break;
			}
			// std::cout << "\033[6n";
			// std::cout.flush();
			// char buff[32];
			// if(std::cin.get() == '\033')
			// {
			// 	if (std::cin.get() == '[')
			// 		std::cin.getline(buff, sizeof(buff), 'R');
			// }
			// int row, col;
			// if (sscanf(buff, "%d;%d", &row, &col) == 2)
			// 	std::cout << "pos buff " << row << " : " << col << std::endl;
			// else
			// 	std::cerr << "err";	
			// std::cout << "\033[u";
			// std::cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
			std::cout << "\033[10A";
			std::cout << "\033[J";
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
		catch(const std::exception & e)
			{ MyStyl::addWhat(e.what()); }		
	}	
	return (0);
}

// int main( void )
// {	
// 	std::srand(static_cast<unsigned int>(std::time(NULL)));
// 	Span sp(16000);
// 	// int arr[] = {2, 1};
// 	// int arr2[] = {4, 4};
// 	// sp.addNumber(24);
// 	// sp.addNumber(29);
// 	// std::cout << " set: " << sp << std::endl;
// 	// sp.addNumber(arr, arr + 2);
// 	// std::cout << " set: " << sp << std::endl;
// 	// sp.addNumber(arr2, arr2 + 2);
// 	// std::cout << " set: " << sp << std::endl;
// 	// std::list<int> list(4,5);
// 	// sp.addNumber(list.begin(), list.end()); //verif distance work with list
// 	// std::cout << " set: " << sp << std::endl;
// 	// std::cout << " yolo" << std::endl;
// 	// std::cout << sp.longestSpan() << std::endl;
// 	// std::cout << " yolo2" << std::endl;
// 	// std::cout << sp.shortestSpan() << std::endl;

// 	std::vector<int> big(15000);
// 	std::generate(big.begin(), big.end(), getRandom);
// 	sp.addNumber(big.begin(), big.end());
// 	std::cout << sp.longestSpan() << std::endl;
// 	std::cout << " yolo2" << std::endl;
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << " set: " << sp << std::endl;
	
// 	// sp.addNumber(42);
// 	// std::cout << " set: " << sp << std::endl;
// 	// sp.addNumber(43);
// 	// std::cout << " set: " << sp << std::endl;
// 	// sp.addNumber(46);
// 	// std::cout << " set: " << sp << std::endl;
// 	// std::for_each(arr, arr+2, print<int>);	
// 	// operator<< <int>(std::cout, sp );
	
// 	return (0);
// }
// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }
// int main()
// {
// Span sp = Span(5);
// sp.addNumber(-24);
// sp.addNumber(-22);
// sp.addNumber(0);
// sp.addNumber(10);
// sp.addNumber(16);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }