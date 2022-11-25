/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:41:36 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 14:41:36 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->_type = "Dog";
	std::cout << "Dog() default constructor called: " << this->_type << " created" << std::endl;
}

Dog::Dog(std::string name) : Animal(name)
{
	std::cout << "Dog( " << name << " ) constructor called: " << this->_type << " created" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	*this = src;
	std::cout << "Dog Copy constructor called: " << this->_type << " created" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->_type = rhs._type;
	std::cout << "Dog Assignment operator called: " << this->_type << " created" << std::endl;
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << this->_type << " does : Woof ! Because he is a Dog." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called : \t" << this->_type << " destroyed" << std::endl;
}

