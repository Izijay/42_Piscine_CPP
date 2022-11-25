/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:51:37 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/29 11:12:03 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat;
	Bureaucrat	bureaucrat2("Robert", 1);
	Bureaucrat	bureaucrat3("Jean", 150);
	std::cout << std::endl;

	std::cout << bureaucrat;
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
	
	Bureaucrat	bureaucrat4("Wrong1", 0);
	Bureaucrat	bureaucrat5("Wrong2", 151);
	Bureaucrat	bureaucrat6("Wrong3", -1);
	std::cout << std::endl;
	
	return (0);
}