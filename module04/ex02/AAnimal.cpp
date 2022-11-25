/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:33:32 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 14:33:32 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_type = "AAnimal";
	std::cout << "AAnimal() constructor called : " << this->_type << " created" << std::endl;
}

AAnimal::AAnimal(std::string name) : _type(name)
{
	std::cout << "AAnimal( " << name << " ) constructor called: " << this->_type << " created" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	*this = src;
	std::cout << "AAnimal Copy constructor called: " << this->_type << " created" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	this->_type = rhs._type;
	std::cout << "AAnimal Assignment operator called: " << this->_type << " created" << std::endl;
	return (*this);
}

std::string	AAnimal::getType( void ) const
{
	return (this->_type);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called : \t" << this->_type << " destroyed" << std::endl;
}