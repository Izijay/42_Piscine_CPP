/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:40:53 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/20 10:39:30 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class	Fixed {

	public:
		Fixed( void );							// Constructor
		Fixed( Fixed const &src );				// Copy constructor
		Fixed( int const n );					// Int constructor
		Fixed( float const n );					// Float constructor
		~Fixed( void );							// Destructor
		Fixed &operator=( Fixed const &rhs );	// Assignment operator overload

		// Comparison operator overloads
		bool	operator>( Fixed const &rhs ) const;
		bool	operator<( Fixed const &rhs ) const;
		bool	operator>=( Fixed const &rhs ) const;
		bool	operator<=( Fixed const &rhs ) const;
		bool	operator==( Fixed const &rhs ) const;
		bool	operator!=( Fixed const &rhs ) const;
		// Arithmetic operator overloads
		Fixed	operator+( Fixed const &rhs ) const;
		Fixed	operator-( Fixed const &rhs ) const;
		Fixed	operator*( Fixed const &rhs ) const;
		Fixed	operator/( Fixed const &rhs ) const;
		// Increment/Decrement operator overloads
		Fixed	&operator++( void );
		Fixed	&operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );
		
		// Setters & Getters
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		// Member functions
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed	&min( Fixed &a, Fixed &b );
		static Fixed	&max( Fixed &a, Fixed &b );
		static Fixed const &min( Fixed const &a, Fixed const &b );
		static Fixed const &max( Fixed const &a, Fixed const &b );
		
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits;

};

std::ostream &operator<<( std::ostream &ofs, Fixed const &rhs );

#endif // FIXED_HPP