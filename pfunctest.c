/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfunctest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 07:04:26 by seblin            #+#    #+#             */
/*   Updated: 2024/07/17 09:18:31 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef int (*mi)(char *, int);
typedef long int what;
typedef what te;
typedef struct set
{
	
} blou;

int func(char *s, int i)
{
	printf("%s et %i\n", s, i);
}

void test(int (*f) (char *, int))
{
	f("yo", 17);
}

int main (void)
{
	func("c", 42);
	test(func);
	int (*arr[2]) (char *, int);
	mi mis[2];
	arr[0] = &func;
	arr[1] = func;
	mis[0] = func, mis[1] = func; 
	mis[1]("mis", 12), (*arr[1])("arr", 15);
	return (0);
}