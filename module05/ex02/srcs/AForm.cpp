/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:21:32 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/04 11:24:32 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high for this Form");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low for this Form");
}

const char 	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed yet");
}

const char	*AForm::FormAlreadySignedException::what() const throw()
{
	return ("Form is already Signed.");
}

AForm::AForm() : _name("DEFAULT Form"), _gradeToSign(50), _gradeToExecute(10), _signed(false)
{
	std::cout << "AForm( void ) Constructor called -- ";
	std::cout << "a DEFAULTAForm has been created" << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : 
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	std::cout << "AForm( " << _name << ", " << _gradeToSign << ", " << _gradeToExecute; 
	std::cout << " ) Constructor called --- ";
	try {
		if (gradeToSign < 1 || gradeToExecute < 1)
			throw AForm::GradeTooHighException();
		if (gradeToExecute > 150 || gradeToSign > 150)
			throw AForm::GradeTooLowException();
		else
			std::cout << "Form " << _name << " created." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name + ": " + e.what() << std::endl;
	}
}

AForm::AForm(AForm const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _signed(src._signed)
{
	std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	std::cout << "AForm::operator= called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	try {
		if (this->_signed == true)
			throw AForm::FormAlreadySignedException();
		else if (bureaucrat.getGrade() > this->_gradeToSign)
			throw AForm::GradeTooLowException();
		else
			this->_signed = true;
	}
	catch (std::exception &e) {
		std::cout << this->_name + ": " + e.what() << std::endl;
	}
}

std::string const &AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

unsigned int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

unsigned int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called --- ";
	std::cout << "Form " << _name << " deleted." << std::endl;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
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