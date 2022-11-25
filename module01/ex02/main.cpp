/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:50:57 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/15 13:02:10 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	try{
		std::string	str = "HI THIS IS BRAIN";
		std::string *stringPTR = &str;
		std::string &stringREF = str;

		std::cout << "Address of str:\t\t" << &str << std::endl;
		std::cout << "Address of stringPTR:\t" << stringPTR << std::endl;
		std::cout << "Address of stringREF:\t" << &stringREF << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Value of str:\t\t" << str << std::endl;
		std::cout << "Value of stringPTR:\t" << *stringPTR << std::endl;
		std::cout << "Value of stringREF:\t" << stringREF << std::endl;

		return (0);
	}
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
		return (0);
	}
}