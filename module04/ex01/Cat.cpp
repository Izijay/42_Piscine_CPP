/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:41:28 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 14:41:28 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	this->_type = "Cat";
	std::cout << "Cat() default constructor called: " << this->_type << " created" << std::endl;
}

Cat::Cat(std::string name) : Animal(name), _brain(new Brain())
{
	std::cout << "Cat( " << name << " ) constructor called: " << this->_type << " created" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	this->_brain = new Brain(*src._brain);
	std::cout << "Cat Copy constructor called: " << src._type << " created" << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	this->_type = rhs._type;
	this->_brain = new Brain(*rhs._brain);
	std::cout << "Cat Assignment operator called: " << this->_type << " created" << std::endl;
	return (*this);
}

const std::string	&Cat::getIdea( int i) const
{
	return (this->_brain->getIdea(i));
}

void	Cat::setIdea(int i, std::string &idea)
{
	this->_brain->setIdea(i, idea);
}

void	Cat::makeSound( void ) const
{
	std::cout << this->_type << " does : Miaaouuuuu ! Because he is a Cat." << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Destructor called : \t" << this->_type << " destroyed" << std::endl;
}