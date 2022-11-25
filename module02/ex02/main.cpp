/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:48:38 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/20 10:51:27 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "a is : " << a << std::endl;
	std::cout << "pre increment a is : " << ++a << std::endl;
	std::cout << "a is : " << a << std::endl;
	std::cout << "post increment a is : " << a++ << std::endl;
	std::cout << "a is : " << a << std::endl;
	
	std::cout << "b is : " << b << std::endl;
	
	std::cout << "Max between a and b is : " << Fixed::max( a, b ) << std::endl;
	
	return (0);
}