/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:56:23 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/30 11:54:04 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

class 	Convert
{
	public:
		Convert(std::string const &str);
		Convert(Convert const &src);
		virtual ~Convert(void);

		Convert &operator=(Convert const &rhs);

		void	getInt(std::ostream & o) const;
		void	getFloat(std::ostream & o) const;
		void	getDouble(std::ostream & o) const;
		void	getChar(std::ostream & o) const;
		double  getValue( void ) const;

	private:
		std::string	_str;
		double		_value;
};

std::ostream &operator<<(std::ostream &o, Convert const &rhs);