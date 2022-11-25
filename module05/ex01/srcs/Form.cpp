/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:21:32 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/04 11:49:25 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char 	*Form::GradeTooHighException::what() const throw() {
	return "Grade too high for this Form";
}

const char 	*Form::GradeTooLowException::what() const throw() {
	return "Grade too low for this Form";
}

const char	*Form::FormAlreadySignedException::what() const throw()
{
	return ("Form is already Signed.");
}

Form::Form() : _name("DEFAULT Form"), _gradeToSign(50), _gradeToExecute(10), _signed(false)
{
	std::cout << "Form::Form( void ) Constructor called -- ";
	std::cout << "a DEFAULT Form has been created" << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : 
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	std::cout << "Form::Form( " << _name << ", " << _gradeToSign << ", " << _gradeToExecute; 
	std::cout << " ) Constructor called --- ";
	try {
		if (gradeToSign < 1 || gradeToExecute < 1)
			throw Form::GradeTooHighException();
		if (gradeToExecute > 150 || gradeToSign > 150)
			throw Form::GradeTooLowException();
		else
			std::cout << "Form " << _name << " created." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name + ": " + e.what() << std::endl;
	}
}

Form::Form(Form const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _signed(src._signed)
{
	std::cout << "Form::Form Copy Constructor called" << std::endl;
}

Form	&Form::operator=(Form const &rhs)
{
	std::cout << "Form::operator= called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	try {
		if (this->_signed == true)
			throw Form::FormAlreadySignedException();
		else if (bureaucrat.getGrade() > this->_gradeToSign)
			throw Form::GradeTooLowException();
		else
			this->_signed = true;
	}
	catch (std::exception &e) {
		std::cout << this->_name + ": " + e.what() << std::endl;
	}
}

std::string const &Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

unsigned int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

unsigned int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

Form::~Form()
{
	std::cout << "Form Destructor called --- ";
	std::cout << "Form " << _name << " deleted." << std::endl;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form " << rhs.getName() << " is ";
	if (rhs.getSigned() == true)
		o << "signed." << std::endl;
	else
		o << "not signed." << std::endl;
	o << "Grade to sign: " << rhs.getGradeToSign() << std::endl;
	o << "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
	return (o);
}