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

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	this->_type = "Dog";
	std::cout << "Dog() default constructor called: " << this->_type << " created" << std::endl;
}

Dog::Dog(std::string name) : Animal(name), _brain(new Brain())
{
	std::cout << "Dog( " << name << " ) constructor called: " << this->_type << " created" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	this->_brain = new Brain(*src._brain);
	std::cout << "Dog Copy constructor called: " << src._type << " created" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->_type = rhs._type;
	this->_brain = new Brain(*rhs._brain);
	std::cout << "Dog Assignment operator called: " << this->_type << " created" << std::endl;
	return (*this);
}

const std::string	&Dog::getIdea( int i) const
{
	return (this->_brain->getIdea(i));
}

void	Dog::setIdea(int i, std::string &idea)
{
	this->_brain->setIdea(i, idea);
}

void	Dog::makeSound( void ) const
{
	std::cout << this->_type << " does : Woof ! Because he is a Dog." << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog Destructor called : \t" << this->_type << " destroyed" << std::endl;
}

