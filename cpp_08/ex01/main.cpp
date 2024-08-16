/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:42:01 by seblin            #+#    #+#             */
/*   Updated: 2024/08/16 11:15:41 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MyStyl.hpp>
#include <Span.hpp>
#include <algorithm>
#include <list>
#include <vector>
#include <ctime>
// template <class T>
// void	print(const T & item)
// {
// 	std::cout << item << std::endl;	
// }

int getRandom()
{
	return rand() - RAND_MAX / 2;
}





int main( void )
{
	std::cout << std::endl << std::endl << std::endl;
	
	{
		MyStyl::addTest("exception N max");	
		try	{
			MyStyl::addActionTest("create span with N = 0");		
			Span sp(0);
			MyStyl::addActionTest("add a number");
			sp.addNumber(1);
		}
		catch(const std::exception & e)
			{ MyStyl::addWhatTest(e.what()); }

		
		try	{
			MyStyl::addActionTest("create span with N = 4");

			Span sp(4);
			MyStyl::addActionTest("add a plage of 5 items");
			int arr[] = {2, 1, 99, -100, -200};
			sp.addNumber(arr, arr + 5);	
		}
		catch(const std::exception & e)
			{ MyStyl::addWhatTest(e.what()); }	
	}
	
	std::cout << std::endl << std::endl;
	
	{
		MyStyl::addTest("exception inversed");		
		try	{
			MyStyl::addActionTest("create span with N = 4");
			Span sp(4);
			MyStyl::addActionTest("add an inversed plage of 5 items");
			int arr[] = {2, 1, 99, -100, -200};
			sp.addNumber(arr + 5, arr);	
		}
		catch(const std::exception & e)
			{ MyStyl::addWhatTest(e.what()); }
	}

	std::cout << std::endl << std::endl;
	
	{
		MyStyl::addTest("operator = ");		
		try	{
			MyStyl::addActionTest("create span with N = 4");
			Span sp(4);
			
			MyStyl::addActionTest("fill it");
			{
				int arr[] = {1, 99, -100, -200};
				sp.addNumber(arr, arr + 4);				
			}			
			
			MyStyl::addActionTest("create span 2 with N = 7");
			Span * sp2 = new Span(7);
			MyStyl::addActionTest("fill it");
			{				
				int arr[] = {2, 1, 99, -100, -200, 42, 24};
				sp2->addNumber(arr, arr + 7);
			}
			std::cout << std::endl;
			MyStyl::addActionTest("display span");
			std::cout << sp << std::endl;
			MyStyl::addActionTest("display span 2");
			std::cout << *sp2 << std::endl;
			MyStyl::addActionTest("span = span 2");
			sp = *sp2;
			MyStyl::addActionTest("delete span 2");
			delete sp2;
			std::cout << std::endl;
			MyStyl::addActionTest("display span");
			std::cout << sp << std::endl;			
		}
		catch(const std::exception & e)
			{ MyStyl::addWhatTest(e.what()); }
	}

	std::cout << std::endl << std::endl;
	
	{
		MyStyl::addTest("const cpy");		
		try	{			
			MyStyl::addActionTest("create span 2 with N = 7");
			Span * sp2 = new Span(7);
			MyStyl::addActionTest("fill it");
			{				
				int arr[] = {2, 1, 99, -100, -200, 42, 24};
				sp2->addNumber(arr, arr + 7);
			}
			std::cout << std::endl;		
			MyStyl::addActionTest("display span 2");
			std::cout << *sp2 << std::endl;
			MyStyl::addActionTest("create span(span 2)");
			Span sp(*sp2);
			MyStyl::addActionTest("delete span 2");
			delete sp2;
			std::cout << std::endl;
			MyStyl::addActionTest("display span");
			std::cout << sp << std::endl;			
		}
		catch(const std::exception & e)
			{ MyStyl::addWhatTest(e.what()); }
	}

	std::cout << std::endl << std::endl;
	
	{
		MyStyl::addTest("longest span");		
		try	{			
			MyStyl::addActionTest("create span with list plage");
			Span * sp2 = new Span(7);
			MyStyl::addActionTest("fill it");
			{				
				int arr[] = {2, 1, 99, -100, -200, 42, 24};
				sp2->addNumber(arr, arr + 7);
			}
			std::cout << std::endl;		
			MyStyl::addActionTest("display span 2");
			std::cout << *sp2 << std::endl;
			MyStyl::addActionTest("create span(span 2)");
			Span sp(*sp2);
			MyStyl::addActionTest("delete span 2");
			delete sp2;
			std::cout << std::endl;
			MyStyl::addActionTest("display span");
			std::cout << sp << std::endl;			
		}
		catch(const std::exception & e)
			{ MyStyl::addWhatTest(e.what()); }
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