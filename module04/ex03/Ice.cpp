/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:34:11 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/27 14:28:51 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	this->_type = "ice";
	std::cout << "Ice constructor called" << std::endl;
	return ;
}

Ice::Ice(Ice const & src) : AMateria("ice")
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
	return ;
}

Ice	&Ice::operator=(Ice const & rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}