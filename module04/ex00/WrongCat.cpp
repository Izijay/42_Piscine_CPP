/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:43:55 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/21 15:43:55 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	this->_type = "WrongCat";
	std::cout << "WrongCat() default constructor called: " << this->_type << " created" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name)
{
	this->_type = name;
	std::cout << "WrongCat( " << name << " ) constructor called: " << this->_type << " created" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	*this = src;
	std::cout << "WrongCat Copy constructor called: " << this->_type << " created" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	this->_type = rhs._type;
	std::cout << "WrongCat Assignment operator called: " << this->_type << " created" << std::endl;
	return (*this);
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat makeSound() called : MIAOU" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called : \t" << this->_type << " destroyed" << std::endl;
}
