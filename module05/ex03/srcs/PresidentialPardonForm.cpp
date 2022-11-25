/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:41:30 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/23 15:38:38 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm( " << _target << " ) constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm("Presidential Pardon", 25, 5), _target(src._target)
{
	std::cout << "PresidentialPardonForm( " << _target << " ) copy constructor called" << std::endl;
}

PresidentialPardonForm 	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "PresidentialPardonForm( " << _target << " ) operator= called" << std::endl;
	_target = rhs._target;
	return (*this);
}

std::string	const &PresidentialPardonForm::getTargetName() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= 5)
	{
		std::cout << _target << " a été pardonnée par Zaphod Beeblebrox" << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat " << executor.getName() << " cannot execute " << _target << " because of his grade" << std::endl;
	}
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm( " << _target << " ) destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &rhs)
{
	os << "Form name: " << rhs.getName() << " , 25 or more to sign, 5 or more to execute. --- Target is: " << rhs.getTargetName() << std::endl;
	return (os);
}