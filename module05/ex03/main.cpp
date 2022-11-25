/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:51:37 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/28 18:04:05 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat("Robert", 20);
	AForm		*form;
	AForm		*form2;
	AForm		*form3;
	Intern		intern;

	std::cout << std::endl;
	form = intern.makeForm("Doesnt", "Work");
	std::cout << std::endl;
	
	form = intern.makeForm("Robotomy Request", "Bureaucrat");
	form->beSigned(bureaucrat);
	std::cout << *form;
	form->execute(bureaucrat);
	std::cout << std::endl;

	form3 = intern.makeForm("Presidential Pardon", "Bureaucrat");
	form3->beSigned(bureaucrat);
	std::cout << *form3;
	form3->execute(bureaucrat);
	std::cout << std::endl;

	form2 = intern.makeForm("Shrubbery Creation", "Bureaucrat");
	form2->beSigned(bureaucrat);
	std::cout << *form2;
	form2->execute(bureaucrat);
	std::cout << std::endl;

	delete form;
	delete form2;
	delete form3;
	return (0);
}