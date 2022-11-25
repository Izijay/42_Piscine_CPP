/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:39:45 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 15:39:45 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name)
{
	this->_type = name;
	std::cout << "WrongAnimal( " << name << " ) constructor called: " << this->_type << " created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	*this = src;
	std::cout << "WrongAnimal Copy constructor called: " << this->_type << " created" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->_type = rhs._type;
	std::cout << "WrongAnimal Assignment operator called: " << this->_type << " created" << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal makeSound() called : MIAOU WAF BHEEE BZZZZZ" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called : " << this->_type << " destroyed" << std::endl;
}