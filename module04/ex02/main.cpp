/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:56:44 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 14:56:44 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iomanip>
#include <iostream>

int	main( void )
{
	// Subject's main :
	{
		const size_t	count = 10;
		AAnimal*			animals[count];

		for (size_t i = 0; i < count; i++) 
		{
			if (i % 2) 	
				animals[i] = new Dog(); 
			else
				animals[i] = new Cat(); 
		}
		for (size_t i = 0; i < count; i++)
			delete animals[i];
	}

	std::cout << std::endl << "=========================================" << std::endl << std::endl;

	// My main :
	{
		Cat	a;
		std::string	first("I'm a cat");
		std::string	idea("I need FOOD !");
		std::cout << std::endl;

		a.setIdea(0, first); 		//set idea of the original cat

		Cat b(a);					//make a copy of the original cat
		std::cout << std::endl;
		std::cout << "Original cat\'s Idea : " << a.getIdea(0) << std::endl; //print the original cat's idea (I'm a cat)
		std::cout << "Copied cat\'s Idea : " << b.getIdea(0) << std::endl; 	// should be "I'm a cat" (the original cat's idea copied)
		a.setIdea(0, idea);		// change the idea of the original cat
		std::cout << "Update the original cat\'s idea : " << a.getIdea(0) << std::endl; // should be "I need FOOD !" (the original cat's idea)
		std::cout << "Copied cat\'s idea dont change : " << b.getIdea(0) << std::endl; // should be "I'm a cat" (the copy cat's idea)
		std::cout << std::endl;

		
		//AAnimal test; // should throw a compilation error (AAnimal is an abstract class)

		return (0);
	}
}
