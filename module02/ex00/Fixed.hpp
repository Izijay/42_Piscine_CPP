/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:40:53 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/20 10:18:45 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class	Fixed {

	public:
		Fixed( void ); 							//Constructor
		Fixed( Fixed const &src ); 				//Copy constructor
		~Fixed( void ); 						//Destructor
		Fixed &operator=( Fixed const &rhs ); 	//Assignment operator overload

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits;

};


#endif // FIXED_HPP