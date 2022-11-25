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

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat("Sawyer");
	const Animal* j = new Dog();
	
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 	//will output the cat sound!
	j->makeSound(); 	//will output the dog sound!
	meta->makeSound(); 	//will output the animal default sound!
	std::cout << std::endl;
	
	const WrongAnimal* k = new WrongCat("The Bad Cat");
	const WrongCat* l = new WrongCat("The Real One");

	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	k->makeSound(); 	//will output the wrong animal default sound instead of WrongCat's one!
	l->makeSound();		//will output the WrongCat sound, because 'l' is of type WrongCat !
	std::cout << std::endl;
	
	delete meta;
	delete j;
	delete i;
	delete k;
	delete l;
	return (0);
}