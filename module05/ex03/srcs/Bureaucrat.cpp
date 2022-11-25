/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:37:35 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/28 18:00:25 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Bureaucrat::Bureaucrat() : _name("DEFAULT"), _grade(150)
{
	std::cout << "Bureaucrat( void ) constructor called --- ";
	std::cout << "Bureaucrat " << _name << " constructed with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat(" << name << ", " << grade << ") Constructor called --- ";
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			std::cout << "Bureaucrat " << _name << " created" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << name + ": " + e.what() << std::endl;
	}
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat 	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

void	Bureaucrat::signForm(AForm &form)
{
	if (this->_grade > form.getGradeToSign())
		std::cout << this->_name << " cannot sign " << form.getName() << " because his grade is too low." << std::endl;
	else if (form.getSigned())
		std::cout << this->_name << " signs " << form.getName() << std::endl;	
}

void	Bureaucrat::executeForm(AForm &form)
{
	try {
		if (this->_grade > form.getGradeToExecute())
			throw Bureaucrat::GradeTooLowException();
		else if (form.getSigned()) {
			form.execute(*this);
			std::cout << this->_name << " executed " << form.getName() << std::endl;
		}
		else
			throw AForm::FormNotSignedException();

	}
	catch (std::exception &e) {
		std::cout << this->_name << ": " << e.what() << std::endl;
	}
}

std::string const &Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void		Bureaucrat::incGrade()
{
	try {
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else {
			this->_grade--;
			std::cout << "Bureaucrat " << _name << " grade increased to " << _grade << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << this->_name + ": " + e.what() << std::endl;
	}
}

void		Bureaucrat::decGrade()
{
	try {
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else {
			this->_grade++;
			std::cout << "Bureaucrat " << _name << " grade decreased to " << _grade << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << this->_name + ": " + e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called -- " << "Bureaucrat " + this->_name + " deleted" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b) {

	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (os);
}