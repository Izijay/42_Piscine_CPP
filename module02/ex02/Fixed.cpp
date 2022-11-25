/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:40:54 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/20 10:53:22 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed( void ) : _fixedPointValue(0)
{
}

Fixed::Fixed( Fixed const &src )
{
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

bool	Fixed::operator>( Fixed const &rhs ) const
{
	return (this->_fixedPointValue > rhs.getRawBits());
}

bool	Fixed::operator<( Fixed const &rhs ) const
{
	return (this->_fixedPointValue < rhs.getRawBits());
}

bool	Fixed::operator>=( Fixed const &rhs ) const
{
	return (this->_fixedPointValue >= rhs.getRawBits());
}

bool	Fixed::operator<=( Fixed const &rhs ) const
{
	return (this->_fixedPointValue <= rhs.getRawBits());
}

bool	Fixed::operator==( Fixed const &rhs ) const
{
	return (this->_fixedPointValue == rhs.getRawBits());
}

bool	Fixed::operator!=( Fixed const &rhs ) const
{
	return (this->_fixedPointValue != rhs.getRawBits());
}

Fixed	Fixed::operator+( Fixed const &rhs ) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-( Fixed const &rhs ) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*( Fixed const &rhs ) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/( Fixed const &rhs ) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++( void )
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	result;
	result._fixedPointValue = this->_fixedPointValue++;
	return (result);
}

Fixed	&Fixed::operator--( void )
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	result;
	result._fixedPointValue = this->_fixedPointValue--;
	return (result);
}

float	Fixed::toFloat( void ) const
{
	return (float(this->_fixedPointValue) / (1 << _fractionalBits));
}

int	Fixed::toInt( void ) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b )
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max( Fixed const &a, Fixed const &b )
{
	if (a > b)
		return (a);
	return (b);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits( int const raw )
{
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

