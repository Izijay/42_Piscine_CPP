/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:01:42 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/04 16:42:43 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(std::string const &str) : _str(str), _value(0)
{
	char	c;
	
	if (str.length() == 1 && (str[0] < '0' || str[0] > '9')) {
		c = str.c_str()[0];
		this->_value = static_cast<double>(c);
	}
	else if (str[str.length() - 1] == 'f' && str != "-inf" && str != "inf" && str != "+inf")
		this->_value = strtod(str.c_str(), NULL);
	else if (str == "-inf" || str == "inf" || str == "+inf" || str == "nan" || str.find('.') != str.npos) {
		this->_value = strtod(str.c_str(), NULL);
	}
	else 
		this->_value = strtod(str.c_str(), NULL);
	return ;		
}

Convert::Convert(Convert const &src)
{
	this->_str = src._str;
	this->_value = src._value;
}

Convert	&Convert::operator=(Convert const &rhs)
{
	if (this != &rhs)
	{
		this->_str = rhs._str;
		this->_value = rhs._value;
	}
	return (*this);
}

void	Convert::getInt(std::ostream & o) const
{
	
	if (this->getValue() > std::numeric_limits<int>::max() || \
		-this->getValue() < std::numeric_limits<int>::min() || \
		std::isinf(this->getValue()) || std::isnan(this->getValue())) {
		o << "impossible" << std::endl;
		return ;
	}
	o << static_cast<int>(this->getValue()) << std::endl;
	return ;	
}

void	Convert::getFloat(std::ostream & o) const
{
	if (std::isnan(this->getValue())) {
		o << "nanf" << std::endl;
		return ;
	}
	else if (std::isinf(this->getValue())) {
		o << (this->getValue() < 0 ? "-inff" : "inff") << std::endl;
		return ;
	}
	if (this->getValue() > std::numeric_limits<float>::max() || \
		-this->getValue() > std::numeric_limits<float>::max() - 1.0) {
		o << "impossible" << std::endl;
		return ;
	}
	o << std::fixed << std::setprecision(1) << static_cast<float>(this->getValue()) << "f" << std::endl;
	return ;	
}

void	Convert::getDouble(std::ostream & o) const
{	
	if (std::isnan(this->getValue())) {
		o << "nan" << std::endl;
		return ;
	}
	else if (std::isinf(this->getValue())) {
		o << (this->getValue() < 0 ? "-inf" : "inf") << std::endl;
		return ;
	}
	if (this->getValue() > std::numeric_limits<double>::max() || \
		-this->getValue() > std::numeric_limits<double>::max() - 1.0) {
		o << "impossible" << std::endl;
		return ;
	}
	o << std::fixed << std::setprecision(1) << static_cast<double>(this->getValue()) << std::endl;
	return ;	
}

void	Convert::getChar(std::ostream & o) const
{
	if (this->getValue() < 0 || this->getValue() > 127 || this->getValue() != this->getValue()) {
		o << "impossible" << std::endl;
		return ;
	}
	else if (this->getValue() < 32 || this->getValue() == 127) {
		o << "Non displayable" << std::endl;
		return ;
	}	
	o << "\'" << static_cast<char>(this->getValue()) << "\'" << std::endl;
	return ;	
}

double	Convert::getValue(void) const
{
	return (this->_value);
}

Convert::~Convert(void)
{
}

std::ostream &operator<<(std::ostream &o, Convert const &rhs)
{
	o << "char : ";
	rhs.getChar(o);
	o << "int : ";
	rhs.getInt(o);
	o << "float : ";
	rhs.getFloat(o);
	o << "double : ";
	rhs.getDouble(o);
	return (o);
}