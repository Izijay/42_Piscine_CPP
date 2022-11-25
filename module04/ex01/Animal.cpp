/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:33:32 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 14:33:32 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "Animal";
	std::cout << "Animal() constructor called : " << this->_type << " created" << std::endl;
}

Animal::Animal(std::string name) : _type(name)
{
	std::cout << "Animal( " << name << " ) constructor called: " << this->_type << " created" << std::endl;
}

Animal::Animal(Animal const &src)
{
	*this = src;
	std::cout << "Animal Copy constructor called: " << this->_type << " created" << std::endl;
}

Animal	&Animal::operator=(Animal const &rhs)
{
	this->_type = rhs._type;
	std::cout << "Animal Assignment operator called: " << this->_type << " created" << std::endl;
	return (*this);
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}

void	Animal::makeSound( void ) const
{
	std::cout << this->_type << " does : MIAOU WAF BHEEE BZZZZZ ! Because he has no type." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called : \t" << this->_type << " destroyed" << std::endl;
}