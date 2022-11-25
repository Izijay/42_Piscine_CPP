/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:37:35 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/13 12:51:24 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::setFirstName(std::string name) {

	this->_firstName = name;
}

void	Contact::setLastName(std::string name) {

	this->_lastName = name;
}

void	Contact::setNickname(std::string name) {

	this->_nickname = name;
}

void	Contact::setPhoneNumber(std::string name) {

	this->_phoneNumber = name;
}

void	Contact::setDarkestSecret(std::string name) {

	this->_darkestSecret = name;
}

void	Contact::displayContact(void) const
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << " First Name : " << this->_firstName << std::endl;
	std::cout << " Last Name : " << this->_lastName << std::endl;
	std::cout << " Nickname : " << this->_nickname << std::endl;
	std::cout << " Phone Number : " << this->_phoneNumber << std::endl;
	std::cout << " Darkest Secret : " << this->_darkestSecret << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}

 std::string	Contact::getPhonNumber(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}