/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:49:52 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/28 18:01:00 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char	*Intern::UnknownFormException::what() const throw()
{
	return ("error: please check the name of the form. The valids forms are: Presidential Pardon, Robotomy Request, Shrubbery Creation");
}

Intern::Intern()
{
	std::cout << "Intern constructor called." << std::endl;
	internForms[0] = &Intern::_makeFormShruberry;
	internForms[1] = &Intern::_makeFormRobotomy;
	internForms[2] = &Intern::_makeFormPresidentialPardon;
	return ;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor called." << std::endl;
	*this = src;
	return ;
}

Intern	&Intern::operator=(Intern const &src)
{
	(void)src;
	std::cout << "Intern assignation operator called." << std::endl;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string formName[3] = {
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon"
	};

	try {
		for (int i = 0; i < 3; i++)
		{
			if (name == formName[i])
				return ((this->*internForms[i])(target));
		}
		throw Intern::UnknownFormException();
	}
	catch (Intern::UnknownFormException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (NULL);
}

AForm	*Intern::_makeFormShruberry(std::string name)
{
	std::cout << "Intern creates a Shrubbery Creation form for " << name << std::endl;
	return (new ShrubberyCreationForm(name));
}

AForm	*Intern::_makeFormRobotomy(std::string name)
{
	std::cout << "Intern creates a Robotomy Request form for " << name << std::endl;
	return (new RobotomyRequestForm(name));
}

AForm	*Intern::_makeFormPresidentialPardon(std::string name)
{
	std::cout << "Intern creates a Presidential Pardon form for " << name << std::endl;
	return (new PresidentialPardonForm(name));
}


Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
	return ;
}