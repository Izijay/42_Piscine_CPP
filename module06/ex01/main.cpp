/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:03:55 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/30 12:22:01 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>
#include "Data.hpp"


uintptr_t 	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*deserialize(uintptr_t ptr)
{
	return reinterpret_cast<Data *>(ptr);
}

int main( void )
{
	Data *ptr = new Data;
	uintptr_t nbr;
	Data *ptr2;

	ptr->nonVide = 42;
	std::cout << "ptr's address :\t" << ptr << " --- ptr's value : " << ptr->nonVide << std::endl;
	nbr = serialize(ptr);
	std::cout << "Serialized :\t" << nbr << std::endl;
	ptr2 = deserialize(nbr);
	std::cout << "Deserialized :\t" << ptr2 << " --- ptr2's value : " << ptr2->nonVide << std::endl;
	
	delete ptr;
	return 0;
}