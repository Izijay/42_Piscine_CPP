/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:26:24 by mdupuis           #+#    #+#             */
/*   Updated: 2022/06/13 18:44:53 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( int ac , char **av )
{
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "Usage: ./Harl [DEBUG | INFO | WARNING | ERROR]" << std::endl;
		return (0);
	}
	std::string level = av[1];
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
	{
		std::cout << level << " is not a valid level" << std::endl;
		std::cout << "Usage: ./Harl [DEBUG | INFO | WARNING | ERROR]" << std::endl;
		return (0);
	}
	harl.complain(level);
	return (0);
}