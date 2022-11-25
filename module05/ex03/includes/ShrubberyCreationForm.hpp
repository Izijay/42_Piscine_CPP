/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:37:03 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/23 15:23:14 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class 	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
		
		std::string	const &getTargetName() const;
		void	execute(Bureaucrat const &executor) const;
	
	private:
		std::string _target;


};

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm const &rhs);