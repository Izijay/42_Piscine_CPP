/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:11:19 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/07 11:46:44 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
void	randomTest( void )
{
	T	container;
	T 	container2;
	typename T::iterator it;

	for (int i = 0; i < 10; i++){
		container.push_back(rand() % 50);
		container2.push_back(rand() % 50);
	}

	std::cout << "\t--- Container: " << std::endl;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Searching for: " << 42 << std::endl;
	it = easyfind(container, 42);
	std::cout << "\t--- Container 2 :" << std::endl;
	for (it = container2.begin(); it != container2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Searching for : " << 0 << std::endl;
	it = easyfind(container2, 0);
}

int	main(void)
{
	srand(time(NULL));
	std::cout << "\t\t--- Vector ---" << std::endl;
	randomTest<std::vector<int> >();
	randomTest<std::vector<int> >();
	randomTest<std::vector<int> >();
	std::cout << std::endl << std::endl;
	std::cout << "\t\t--- List ---" << std::endl;
	randomTest<std::list<int> >();
	randomTest<std::list<int> >();
	randomTest<std::list<int> >();
	
	return (0);
}