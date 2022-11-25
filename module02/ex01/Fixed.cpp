/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:40:54 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/20 14:15:13 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( int const n )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = n << this->_fractionalBits;
	return ;
}

Fixed::Fixed( float const n )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
	return ;
}

Fixed	&Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

float	Fixed::toFloat( void ) const
{
	return (float(this->_fixedPointValue) / (1 << _fractionalBits));
}

int	Fixed::toInt( void ) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

std::ostream &operator<<( std::ostream &ofs, Fixed const &rhs )
{
	ofs << rhs.toFloat();
	return (ofs);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

