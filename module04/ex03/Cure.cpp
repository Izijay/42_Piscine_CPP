/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:38:47 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/27 15:29:15 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	this->_type = "cure";
	std::cout << "Cure constructor called" << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure	&Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
	return ;
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}