/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:49:47 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/28 18:01:17 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class 	Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();
		
		Intern &operator=(Intern const &src);

		AForm *makeForm(std::string name, std::string target);
		AForm *(Intern::*internForms[3])(std::string);

		class UnknownFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
	private:
		AForm *_makeFormShruberry(std::string name);
		AForm *_makeFormRobotomy(std::string name);
		AForm *_makeFormPresidentialPardon(std::string name);
};

std::ostream &operator<<(std::ostream &os, Intern const &rhs);