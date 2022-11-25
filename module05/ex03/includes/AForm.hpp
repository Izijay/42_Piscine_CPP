/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:21:30 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/04 13:53:10 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class 	AForm {
	public:
		AForm();
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &src);
		virtual ~AForm();
		
		AForm &operator=(AForm const &rhs);
		
		std::string const &getName() const;
		bool getSigned() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;
		
		void beSigned(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	
	private:
		std::string	const	_name;
		unsigned int const		_gradeToSign;
		unsigned int const		_gradeToExecute;
		bool				_signed;
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);