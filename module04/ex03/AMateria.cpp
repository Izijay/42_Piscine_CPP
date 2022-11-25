/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:06:58 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/27 14:16:40 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->_type = "default";
	std::cout << "AMateria() constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria( type ) constructor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const & src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria &AMateria::operator=(AMateria const & rhs)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
		std::cout << "* shoots " << target.getName() << " with an ice bolt *" << std::endl;
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << " *" << std::endl;
	else
		std::cout << "AMateria::use() : type not found" << std::endl;
	return ;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
	return ;
}