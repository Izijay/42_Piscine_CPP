/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:51:37 by mdupuis           #+#    #+#             */
/*   Updated: 2022/07/04 11:55:46 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat2("Robert", 1);
	Bureaucrat	bureaucrat3("Jean", 150);
	std::cout << std::endl;

	std::cout << bureaucrat2;
	std::cout << bureaucrat3;
	std::cout << std::endl;

	bureaucrat3.decGrade();
	bureaucrat2.incGrade();
	std::cout << bureaucrat3;
	std::cout << bureaucrat2;
	std::cout << std::endl;

	bureaucrat3.incGrade();
	bureaucrat2.decGrade();
	std::cout << bureaucrat3;
	std::cout << bureaucrat2;
	std::cout << std::endl;
	
	Form	form("b12", 2, 50);
	Form	form2;
	std::cout << std::endl;
	std::cout << form;
	std::cout << form2;
	std::cout << std::endl;

	bureaucrat3.signForm(form);
	form.beSigned(bureaucrat3);
	std::cout << form;
	std::cout << std::endl;
	form.beSigned(bureaucrat2);
	bureaucrat2.signForm(form);
	std::cout << form;
	std::cout << std::endl;
	form.beSigned(bureaucrat2);
	std::cout << std::endl;
	
	
	return (0);
}