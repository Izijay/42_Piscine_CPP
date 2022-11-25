/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:40:53 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/20 10:27:13 by mdupuis          ###   ########.fr       */
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
		
		int		getRawBits( void ) const;		// Getter
		void	setRawBits( int const raw );	// Setter
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits;

};

std::ostream &operator<<( std::ostream &ofs, Fixed const &rhs );	// Output operator overload

#endif // FIXED_HPP