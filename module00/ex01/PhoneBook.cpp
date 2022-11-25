/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:41:02 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/14 11:34:14 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	_nbr = 0;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Welcome to this Awesome PhoneBook     |" << std::endl;
	std::cout << "|         Please make your choice...        |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << std::endl;
	while (true)
	{
		std::string choice;
		std::cout << "\ntype ADD.\t\tto Add a contact (maximum 8)" << std::endl;
		std::cout << "type SEARCH.\t\tto Search a contact" << std::endl;
		std::cout << "type EXIT.\t\tto ... Exit" << std::endl;
		std::cout << "\n> What can I do for you ? "<< std::endl;
		do {
			std::getline(std::cin, choice);
			if (std::cin.eof())
				return ;
		}while (choice.empty());
		if (choice == "ADD")
			this->add();
		else if (choice == "SEARCH")
			this->search();
		else if (choice == "EXIT"){
			std::cout << "Have a nice day !\n";
			break;
		}
		else
			std::cout << "Invalid choice." << std::endl;
	}
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string 	trimString(std::string str)
{
	std::string s;
	for (unsigned long i = 0; i < str.size(); i++)
	{
		if (str[i] != '\t')
			s += str[i];
	}
	return (s);
}

void		PhoneBook::_setContact(void)
{
	std::cout << "You want to add a new contact: " << std::endl;

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	
	std::cout << "First Name ?:\t";
	do {
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			return ;
		firstName = trimString(firstName);
	} while (firstName.empty());
	_contacts[_nbr].setFirstName(firstName);
	std::cout << std::endl;
	do {
		std::cout << "Last Name ?:\t";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			return ;
	lastName = trimString(lastName);
	} while (lastName.empty());
	_contacts[_nbr].setLastName(lastName);
	std::cout << std::endl;
	do {
		std::cout << "Nickname ?:\t";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			return ;
		nickname = trimString(nickname);
	} while (nickname.empty());
	_contacts[_nbr].setNickname(nickname);
	std::cout << std::endl;

	do {
		std::cout << "Phone Number ?:\t";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			return ;
		phoneNumber = trimString(phoneNumber);
	} while (phoneNumber.empty());
	_contacts[_nbr].setPhoneNumber(phoneNumber);
	std::cout << std::endl;

	do {
		std::cout << "Darkest Secret ?: ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
			return ;
	} while (darkestSecret.empty());
	_contacts[_nbr].setDarkestSecret(darkestSecret);
	std::cout << std::endl;

	if (_nbr < 8)
		_nbr++;
}


void		PhoneBook::add(void)
{
	std::cin.clear();
	if (_nbr == MAX_CONTACT)
	{
		std::cout << "Maximum of contacts reached. (8)" << std::endl;
		std::cout << "I will delete the oldest one to create a new one." << std::endl;
		 for (int i = 1; i < MAX_CONTACT; i++)
			_contacts[i - 1] = _contacts[i];
		_nbr--;
		_setContact();
	}
	else
		_setContact();
}

bool isNumber(std::string str)
{
 	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (str.length() > 0);
}

void		PhoneBook::_searchByIndex(void)
{
	std::string	whichContact;
	std::string display;
	bool	valid;

	valid = false;
	while (!valid)
	{
		std::cout << "Which one do you wanna know more about ? (0 to return.) > ";
		getline(std::cin, whichContact);
		if (std::cin.eof())
			return ;
		if (isNumber(whichContact) && atoi(whichContact.c_str()) == 0 && whichContact.size() == 1)
			return ;
		else if (isNumber(whichContact) && atoi(whichContact.c_str()) < _nbr + 1 && whichContact.size() == 1)
			valid = true;
		else
			std::cout << whichContact << ": invalid index" << std::endl;
	}
	_contacts[atoi(whichContact.c_str()) - 1].displayContact();

}

void		minString(std::string str)
{
	if (str.size() > 10)
		std::cout << std::right << std::setw(9) << str.substr(0, 9) << ".";
	else
		std::cout << std::right << std::setw(10) << str;
	std::cout << "|";
}

void		PhoneBook::search(void)
{
	if (_nbr == 0)
	{
		std::cout << "No contact stored." << std::endl;
		return ;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "| Please enter the Index of the contact to  |" << std::endl;
	std::cout << "|              see more info...             |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "First Name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Last Name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

	for (int i = 0; i < _nbr ; i++)
	{	
		std::cout << "|";
		std::cout << std::right << std::setw(9) << "#" << i + 1 << "|";
		minString(_contacts[i].getFirstName());
		minString(_contacts[i].getLastName());
		minString(_contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	_searchByIndex();
}
