/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:37:25 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/23 15:36:12 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm( " << target << " ) constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	std::cout << "RobotomyRequestForm( " << src._target << " ) copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm( " << rhs._target << " ) assignment operator called" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

std::string	const &RobotomyRequestForm::getTargetName() const
{
	return _target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try {
		if(this->getSigned() == false)
			throw AForm::FormNotSignedException();
		else if (executor.getGrade() > 45)
			throw AForm::GradeTooLowException();
		else {
			srand(time(NULL));
			int random = rand() % 2 + 1;

			std::cout << "BRRRRzzzzzzRRR BRRRRzzzzzzzzzzzzzzzRRRRrr" << std::endl;
			if (random == 1)
				std::cout << "Robotomy request for " << _target << " has been executed successfully (50% chance)" << std::endl;
			else
				std::cout << "Robotomy request for " << _target << " has failed (50% chance.)" << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception: Robotomy FAILED for " << _target << " because "  << e.what() << std::endl;
	std::cout << "Bureaucrat " << executor.getName() << " " << executor.getGrade() << " " << "execute " << this->getName() << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm( " << _target << " ) destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm const &rhs) {

	os << "Form name: " << rhs.getName() << " , 72 or more to sign, 45 or more to execute. --- Target is: " << rhs.getTargetName() << std::endl;
	return (os);
}
