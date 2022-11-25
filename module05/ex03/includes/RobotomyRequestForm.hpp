/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:37:09 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/23 15:27:51 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class 	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		std::string	const &getTargetName() const;
		void	execute(Bureaucrat const &executor) const;

	private:
		std::string _target;
};

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm const &rhs);