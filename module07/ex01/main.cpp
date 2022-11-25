/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:10:01 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/06 15:21:42 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"

int	main(void) 
{
	int tab[5] = {1, 12, 42, 0, 7};

	std::cout << "Before: " << std::endl;
	for (size_t i = 0; i < 5; i++)
		std::cout << i << " :\t" << tab[i] << std::endl;
	std::cout << std::endl;

	iter(tab, 5, &fctn<int>);
	std::cout << "After: " << std::endl;
	for (size_t i = 0; i < 5; i++)
		std::cout << i << " :\t" << tab[i] << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	char tab2[13] = "Hello World!";
	std::cout << "Before: " << std::endl;
	std::cout << "tab2 :\t" << tab2 << std::endl;
	std::cout << std::endl;
	iter(tab2, 13, &fctn);
	std::cout << "After: " << std::endl;
	std::cout << "tab2 :\t" << tab2 << std::endl;

	return (0);
}