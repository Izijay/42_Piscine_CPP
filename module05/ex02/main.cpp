/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:51:37 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/23 15:44:52 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat2("Robert", 1);
	Bureaucrat	bureaucrat3("Jean", 150);

	std::cout << std::endl << "// ShrubberyCreationForm ------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	ShrubberyCreationForm	scf("ShrubberyForm1");
	std::cout << std::endl;
	std::cout << scf;
	scf.beSigned(bureaucrat3);
	scf.execute(bureaucrat3);
	std::cout << std::endl;
	std::cout << scf;
	bureaucrat2.executeForm(scf);
	scf.beSigned(bureaucrat2);
	bureaucrat2.signForm(scf);
	bureaucrat2.executeForm(scf);
	std::cout << std::endl;
	
	std::cout << "// RobotomyRequestForm ------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	RobotomyRequestForm	rrf("RobotomyForm1");
	std::cout << std::endl;
	std::cout << rrf;
	bureaucrat2.executeForm(rrf);
	rrf.beSigned(bureaucrat2);
	bureaucrat2.signForm(rrf);
	bureaucrat2.executeForm(rrf);
	std::cout << std::endl;
	
	std::cout << "// PresidentialPardonForm ------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	PresidentialPardonForm	ppf("PardonForm1");
	std::cout << std::endl;
	std::cout << ppf;
	bureaucrat2.executeForm(ppf);
	ppf.beSigned(bureaucrat2);
	bureaucrat2.decGrade();
	bureaucrat2.decGrade();
	bureaucrat2.decGrade();
	bureaucrat2.decGrade();
	bureaucrat2.decGrade();
	bureaucrat2.signForm(ppf);
	bureaucrat2.executeForm(ppf);
	bureaucrat2.incGrade();
	bureaucrat2.executeForm(ppf);
	std::cout << std::endl;
	
	return (0);
}