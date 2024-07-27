/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainrhi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:36:27 by svidot            #+#    #+#             */
/*   Updated: 2024/07/27 12:55:44 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
void ft_ptr(int *ptr)
{
   * ptr -= 1;
    
}

int main (void)
{
    int i = 42;

    ft_ptr(&i);
    
    printf("%d\n", i);
    // char s = 's';
    char *a = "a\n";
    write(1, a, 2);
    return 0;
}